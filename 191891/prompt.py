# Refactor the following Python code to improve readability and maintainability. Specifically, simplify the initialization of the QApplication and RootFinder objects, and make the sys.exit(app.exec_()) statement clearer without changing its functionality. Return only the code.
from PyQt5 import QtWidgets
from backend.main_backend import RootFinder 

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    root_finder = RootFinder()
    root_finder.show()
    sys.exit(app.exec_())
