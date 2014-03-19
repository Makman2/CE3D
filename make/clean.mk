# This file is part of CE3D. License: GPL3

# Cleans everything
clean: cleantmp

# Cleans temporary files like editor
cleantmp:
	rm -rf src/*~ *~
