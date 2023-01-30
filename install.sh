#!/bin/bash

USER_HOME=$(getent passwd $SUDO_USER | cut -d: -f6)
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

while getopts ":i:" opt; do
  case $opt in
    i) xtc_path="$OPTARG"
    ;;
    \?) echo "Invalid option -$OPTARG" >&2
    exit 1
    ;;
  esac

  case $OPTARG in
    -*) echo "Option $opt needs a valid argument"
    exit 1
    ;;
  esac
done

xtc_dir="$(basename -- $xtc_path)"
echo "[info] xtc-path: $xtc_path"
echo "[info] xtc-dir: $xtc_dir"
echo "[info] script-dir: $SCRIPT_DIR"

echo "[info] Removing /bin folder if exists"
rm -r -f "$SCRIPT_DIR/bin"

echo "[info] Creating /bin folder for storing XTC files"
mkdir -p "$SCRIPT_DIR/bin/"

echo "[info] Removing /temp folder if exists"
rm -r -f "$SCRIPT_DIR/temp"

echo "[info] Creating /temp folder for unziped files"
mkdir -p "$SCRIPT_DIR/temp/"

echo "[info] Unzip toolchain files"
tar -zxf "$xtc_path" -C "$SCRIPT_DIR/temp"

echo "[info] Moving unziped files"
mv $SCRIPT_DIR/temp/XMOS/XTC/*/* "$SCRIPT_DIR/bin/"

echo "[info] Removing /temp folder"
rm -r -f "$SCRIPT_DIR/temp"

SETUP_CMD="cd \"$SCRIPT_DIR/bin\" && source \"$SCRIPT_DIR/bin/SetEnv\" && export PATH=\"\$PATH:$SCRIPT_DIR/support:$SCRIPT_DIR/bin/bin\""
echo "[info] Writing .profile bash commands"
if grep -xqFe "$SETUP_CMD" "$USER_HOME/.profile"; then
  echo "[info] Startup commands already exist"
else
  echo "$SETUP_CMD" >> "$USER_HOME/.profile"
  source "$USER_HOME/.profile"
fi

echo "[warn] Connect XMOS device"
read -p "Press enter to continue"
echo "[info] Running setup script for devices"
cd "$SCRIPT_DIR/bin/scripts"
./setup_xmos_devices.sh
echo "[warn] Reconnect any currently connected XTAG devices"
read -p "Press enter to continue"
echo "[info] Listing all connected XMOS devices"
./check_xmos_devices.sh
cd ../../
