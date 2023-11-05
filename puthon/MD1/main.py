# Gramatnecbas inventara parvaldibas sistema
# kas izmanto pyqt bibliotieku kā vizualo saskarsni

from PyQt6.QtWidgets import QApplication, QWidget, QHBoxLayout, QVBoxLayout, QLineEdit, QRadioButton, QLabel, QFrame, \
    QSizePolicy, QPushButton, QDialog, QDialogButtonBox

app = QApplication([])
# Global book dict
books = {
    9781234567897: {"title": "", "author": "", "isbn": 9781234567897, "price": 10.0, "stock": 1}
}


# Functions for work with books dictionary

def add_book(title, author, isbn, price, stock):
    if isbn not in books:
        books[isbn] = {"title": title, "author": author, "isbn": isbn, "price": price, "stock": stock}
    else:
        show_error("Book already added")


def remove_book(isbn):
    if isbn in books:
        del books[isbn]
        show_success("book deleted")
    else:
        show_error("isbn not found")


def find_book(isbn):
    if isbn in books:
        return books[isbn]
    else:
        show_error("isbn not found")
        return None


def print_book(book):
    print(book["title"])
    print(book["author"])
    print(book["isbn"])
    print(book["price"])
    print(book["stock"])


def show_error(err):
    print(err)


def show_success(suc):
    print(suc)


def is_float(string):
    if string.replace(".", "").isnumeric():
        return True
    else:
        return False


# Visual stuff
class CustomDialog(QDialog):
    def __init__(self, msg):
        super().__init__()

        self.setWindowTitle("HELLO!")

        QBtn = QDialogButtonBox.StandardButton.Ok

        self.buttonBox = QDialogButtonBox(QBtn)
        self.buttonBox.accepted.connect(self.accept)
        self.buttonBox.rejected.connect(self.reject)

        self.layout = QVBoxLayout()
        message = QLabel(msg)
        self.layout.addWidget(message)
        self.layout.addWidget(self.buttonBox)
        self.setLayout(self.layout)


class Window(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Gramatu sistēma")

        self.layout = QVBoxLayout()

        # Structure:
        # Search bar
        # add new entry
        # list of books
        class SearchBar(QWidget):
            def __init__(self):
                super().__init__()
                self.layout = QHBoxLayout()

                self.textbox = QLineEdit(self)
                self.layout.addWidget(self.textbox)

                class SearchSwitch(QWidget):
                    def __init__(self):
                        super().__init__()
                        self.layout = QVBoxLayout()

                        self.isbnSearch = QRadioButton("ISBN")
                        self.isbnSearch.setChecked(True)
                        self.layout.addWidget(self.isbnSearch)

                        self.nameSearch = QRadioButton("Nosaukums vai autors")
                        self.layout.addWidget(self.nameSearch)

                        self.setLayout(self.layout)

                self.searchSwitch = SearchSwitch()
                self.layout.addWidget(self.searchSwitch)

                self.setLayout(self.layout)

        class AddBook(QWidget):
            def __init__(self):
                super().__init__()
                self.layout = QHBoxLayout()

                class Field(QWidget):
                    def __init__(self, label):
                        super().__init__()
                        self.layout = QHBoxLayout()

                        self.title = QLabel(label)
                        self.layout.addWidget(self.title)

                        self.field = QLineEdit(self)
                        self.layout.addWidget(self.field)

                        self.setLayout(self.layout)

                self.title = QLabel("Pivienot jaunu grāmatu:")
                self.layout.addWidget(self.title)

                self.name = Field("vārds")
                self.layout.addWidget(self.name)
                self.author = Field("autors")
                self.layout.addWidget(self.author)
                self.isbn = Field("ISBN")
                self.layout.addWidget(self.isbn)
                self.price = Field("cena")
                self.layout.addWidget(self.price)
                self.qty = Field("daudzums")
                self.layout.addWidget(self.qty)
                self.add = QPushButton("pievienot")
                self.add.clicked.connect(self.on_save)
                self.layout.addWidget(self.add)

                self.setLayout(self.layout)

            def on_save(self):
                # do some checks
                if not is_float (self.price.field.text()):
                    dlg = CustomDialog("Cena nav skaitlis!")
                    dlg.exec()
                    return
                if not self.price.field.text().isnumeric():
                    dlg = CustomDialog("daudzums nav vesels skaitlis!")
                    dlg.exec()
                    return

                add_book(self.name.field.text(),
                         self.author.field.text(),
                         self.isbn.field.text(),
                         float(self.price.field.text()),
                         int(self.qty.field.text()))

        self.searchbar = SearchBar()
        self.addBook = AddBook()

        self.separator = QFrame()
        self.separator.setFrameShape(QFrame.Shape.HLine)
        self.separator.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)
        self.separator.setLineWidth(3)

        self.layout.addWidget(self.searchbar)
        self.layout.addWidget(self.separator)
        self.layout.addWidget(self.addBook)
        self.setLayout(self.layout)


window = Window()
window.show()
app.exec()
