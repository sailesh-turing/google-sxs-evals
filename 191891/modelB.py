from PyQt5 import QtWidgets
from backend.main_backend import RootFinder
import sys

def main():
    app = QtWidgets.QApplication(sys.argv)
    root_finder = RootFinder()
    root_finder.show()
    exit_code = app.exec_()
    sys.exit(exit_code)

if __name__ == "__main__":
    main()

