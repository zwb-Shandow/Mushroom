#!/usr/bin/env python
 
import pty
import os
import select

def main():
    sender, slave = pty.openpty()
    print(os.ttyname(slave))
    receiver, slave = pty.openpty()
    print(os.ttyname(slave))
    while True:
        data = os.read(sender, 128)
        os.write(receiver, data)

if __name__ == "__main__":
    main()