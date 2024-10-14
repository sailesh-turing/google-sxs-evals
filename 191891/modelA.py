import sys
from PyQt5.QtWidgets import QApplication

from backend.main_backend import RootFinder

if __name__ == "__main__":
    app = QApplication(sys.argv)
    root_finder = RootFinder()
    root_finder.show()
    app.exec_()
    sys.exit()
