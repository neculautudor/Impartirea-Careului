#!/usr/bin/env python3

import sys
import subprocess


def execute(command: list) -> None:
    """This function takes a command and its arguments in the form of a list
    and then executes it. It also displays on the screen any output of the
    executed command (stdout and stderr)"""

    output = subprocess.run(command)
    if output.stdout:
        print('[Output]: ', output.stdout)
    if output.stderr:
        print('[Error]: ', output.stderr)


if __name__ == '__main__':
    if len(sys.argv) == 2:
        filename = sys.argv[1]
        execute(['g++', '-c', filename + '.cpp'])
        execute(['g++', filename + '.o', '-o', 'sfml-app', '-lsfml-graphics',
                '-lsfml-window', '-lsfml-system'])
        execute(['rm', filename + '.o'])  # clean the object file
    else:
        print('Usage: {} <source_name>'.format(sys.argv[0]))
