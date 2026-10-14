
#!/usr/bin/env bash
set -Eeuo pipefail

# Resolve the actual script location, including when invoked through a symlink.
PROJECT_DIR="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
BUILD_DIR="$PROJECT_DIR/build"
ARCHIVE_DIR="$PROJECT_DIR/archives"

ARCHIVE=false

# Parse options
for arg in "$@"; do
    case "$arg" in
        -archive|--archive)
            ARCHIVE=true
            ;;
        -h|--help)
            echo "Usage: gen_proj [-archive | --archive]"
            exit 0
            ;;
        *)
            echo "Unknown option: $arg" >&2
            echo "Usage: gen_proj [-archive | --archive]" >&2
            exit 1
            ;;
    esac
done

# Archive the previous build before deleting it.
if [[ "$ARCHIVE" == true && -d "$BUILD_DIR" ]]; then
    mkdir -p "$ARCHIVE_DIR"
    TIMESTAMP="$(date +%Y-%m-%d_%H-%M-%S)"
    DEST="$ARCHIVE_DIR/build-$TIMESTAMP"

    cp -a "$BUILD_DIR" "$DEST"
    echo "Archived previous build to: $DEST"
elif [[ "$ARCHIVE" == true ]]; then
    echo "No existing build directory to archive."
fi

# Configure and compile
cmake -S "$PROJECT_DIR" -B "$BUILD_DIR"
cmake --build "$BUILD_DIR" --parallel

# Run the executable from the build directory.
cd "$BUILD_DIR"
exec ./Maze-Fall
