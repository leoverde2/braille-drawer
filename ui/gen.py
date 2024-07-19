import os
from pathlib import Path
import subprocess

script_dir = Path(os.path.dirname(os.path.abspath(__file__)))

output_dir = script_dir / "../build/braille-drawer_autogen/include"
output_dir = output_dir.resolve()

for ui_file in script_dir.glob("*.ui"):
    header_file = output_dir / f"ui_{ui_file.stem}.h"

    with open(header_file, "w") as header:
        subprocess.run(["uic", str(ui_file), "-o", str(header_file)])
