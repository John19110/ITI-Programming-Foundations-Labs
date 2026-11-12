#!/bin/sh
# Build and run on Linux and macOS.
cd "$(dirname "$0")" || exit 1

g++ -std=c++17 -I include \
  src/Main.cpp \
  src/Menu.cpp \
  src/Employee.cpp \
  src/Color.cpp \
  -o Menu || exit 1

# Already inside a terminal, including Cursor's integrated terminal.
if [ -t 0 ]; then
  exec ./Menu
fi

# The Run button's output panel cannot read arrow keys.
# Open a real terminal, and leave it open after the program exits.
DIR=$(pwd)
cmd="cd '$DIR' && ./Menu; printf '\nPress Enter to close... '; read _"

if command -v x-terminal-emulator >/dev/null 2>&1; then
  target=$(readlink -f "$(command -v x-terminal-emulator)" 2>/dev/null || true)
  case "$target" in
    *ptyxis*)
      exec ptyxis --new-window -d "$DIR" -- sh -c "$cmd"
      ;;
    *gnome-terminal*)
      exec gnome-terminal --working-directory="$DIR" -- sh -c "$cmd"
      ;;
  esac
fi

if command -v ptyxis >/dev/null 2>&1; then
  exec ptyxis --new-window -d "$DIR" -- sh -c "$cmd"
fi

if command -v gnome-terminal >/dev/null 2>&1; then
  exec gnome-terminal --working-directory="$DIR" -- sh -c "$cmd"
fi

if command -v konsole >/dev/null 2>&1; then
  exec konsole --workdir "$DIR" -e sh -c "$cmd"
fi

if command -v xfce4-terminal >/dev/null 2>&1; then
  exec xfce4-terminal --working-directory="$DIR" --command="sh -c \"$cmd\""
fi

if command -v xterm >/dev/null 2>&1; then
  exec xterm -e sh -c "$cmd"
fi

if command -v x-terminal-emulator >/dev/null 2>&1; then
  exec x-terminal-emulator -e sh -c "$cmd"
fi

echo "No terminal emulator found. Open a terminal in this folder and run ./Menu" >&2
exit 1
