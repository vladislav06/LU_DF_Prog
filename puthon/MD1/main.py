# Gramatnecbas inventara parvaldibas sistema
# kas izmanto pyqt bibliotieku kā vizualo saskarsni

from PyQt6.QtWidgets import QApplication, QWidget, QHBoxLayout, QVBoxLayout, QLineEdit, QRadioButton, QLabel, QFrame, \
    QSizePolicy, QPushButton, QDialog, QDialogButtonBox, QGroupBox, QScrollArea
import isbnlib

app = QApplication([])
# Global book dict
books = {
    "978-7-5035-3452-2": {"title": "The Great Gatsby", "author": "F. Scott Fitzgerald", "isbn": "9781234567891",
                          "price": 12.0, "stock": 5},
    "978-6-0918-1145-9": {"title": "To Kill a Mockingbird", "author": "Harper Lee", "isbn": "9781234567892",
                          "price": 15.0, "stock": 3},
    "978-8-3023-0402-6": {"title": "1984", "author": "George Orwell", "isbn": "9781234567893", "price": 9.99,
                          "stock": 10},
    "978-7-3756-6440-2": {"title": "The Catcher in the Rye", "author": "J.D. Salinger", "isbn": "9781234567894",
                          "price": 20.5, "stock": 2},
    "978-0-8462-4207-9": {"title": "Pride and Prejudice", "author": "Jane Austen", "isbn": "9781234567895",
                          "price": 8.5, "stock": 7},
    "978-0-2050-7751-9": {"title": "The Hobbit", "author": "J.R.R. Tolkien", "isbn": "9781234567896", "price": 14.99,
                          "stock": 6},
    "978-7-6359-8148-5": {"title": "Harry Potter and the Sorcerer's Stone", "author": "J.K. Rowling",
                          "isbn": "9781234567897", "price": 10.0, "stock": 1},
    "978-3-0297-3233-6": {"title": "The Lord of the Rings", "author": "J.R.R. Tolkien", "isbn": "9781234567898",
                          "price": 7.5, "stock": 4},
    "978-5-8552-9325-8": {"title": "To the Lighthouse", "author": "Virginia Woolf", "isbn": "9781234567899",
                          "price": 11.99, "stock": 8},
    "978-7-5708-0459-7": {"title": "The Shining", "author": "Stephen King", "isbn": "9781234567800", "price": 18.0,
                          "stock": 9}

}


# Functions for work with books dictionary

def add_book(title, author, isbn, price, stock):
    if isbn not in books:
        books[isbn] = {"title": title, "author": author, "isbn": isbn, "price": price, "stock": stock}
    else:
        show_error("Grāmata jau eksistē!")


def remove_book(isbn):
    if isbn in books:
        del books[isbn]
        show_success("Grāmata ir izdzesta!")
    else:
        show_error("ISBN nebija atrasts!")


def find_book(isbn):
    if isbn in books:
        return books[isbn]
    else:
        show_error("ISBN nebija atrasts!")
        return None


def print_book(book):
    print(book["title"])
    print(book["author"])
    print(book["isbn"])
    print(book["price"])
    print(book["stock"])


def show_error(err):
    dlg = CustomDialog(err)
    dlg.exec()


def show_success(suc):
    show_error(suc)


def is_float(string):
    if string.replace(".", "").isdigit():
        return True
    else:
        return False


# Visual stuff
class CustomDialog(QDialog):
    def __init__(self, msg):
        super().__init__()

        self.setWindowTitle("")

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
                if len(self.name.field.text()) == 0:
                    dlg = CustomDialog("Vārds nevar būt tukšs")
                    dlg.exec()
                    return

                if len(self.author.field.text()) == 0:
                    dlg = CustomDialog("Autors nevar būt tukšs")
                    dlg.exec()
                    return

                if not isbnlib.is_isbn13(self.isbn.field.text()) and not isbnlib.is_isbn10(self.isbn.field.text()):
                    dlg = CustomDialog("ISBN kļūda")
                    dlg.exec()
                    return
                if not is_float(self.price.field.text()):
                    dlg = CustomDialog("Cena nav positivs skaitlis!")
                    dlg.exec()
                    return

                if not self.qty.field.text().isdigit():
                    dlg = CustomDialog("daudzums nav vesels positivs skaitlis!")
                    dlg.exec()
                    return

                add_book(self.name.field.text(),
                         self.author.field.text(),
                         isbnlib.canonical(self.isbn.field.text()),
                         float(self.price.field.text()),
                         int(self.qty.field.text()))
                self.update()

        self.searchbar = SearchBar()
        self.addBook = AddBook()

        self.separator = QFrame()
        self.separator.setFrameShape(QFrame.Shape.HLine)
        self.separator.setSizePolicy(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding)
        self.separator.setLineWidth(3)

        class BookEntry(QWidget):
            def __init__(self, book):
                super().__init__()
                self.layout = QHBoxLayout()

                self.title = QLabel(book["title"])
                self.author = QLabel(book["author"])
                self.isbn = QLabel(book["isbn"])
                self.price = QLabel(str(book["price"]))
                self.stock = QLabel(str(book["stock"]))

                self.layout.addWidget(self.title)
                self.layout.addWidget(self.author)
                self.layout.addWidget(self.isbn)
                self.layout.addWidget(self.price)
                self.layout.addWidget(self.stock)

                self.setLayout(self.layout)

        class BookList(QWidget):
            def __init__(self):
                super().__init__()
                self.scroll = None
                self.group = None
                self.grouplayout = None
                self.layout = QVBoxLayout()
                self.update_list()

            def update_list(self):
                for i in reversed(range(self.layout.count())):
                    self.layout.itemAt(i).widget().setParent(None)

                self.group = QGroupBox()
                self.grouplayout = QVBoxLayout()

                for isbn in books:
                    self.grouplayout.addWidget(BookEntry(books[isbn]))
                self.group.setLayout(self.grouplayout)
                self.scroll = QScrollArea()
                self.scroll.setWidget(self.group)
                self.scroll.setWidgetResizable(True)
                self.layout.addWidget(self.scroll)
                self.setLayout(self.layout)

        self.books = BookList()

        self.layout.addWidget(self.searchbar)
        self.layout.addWidget(self.separator)
        self.layout.addWidget(self.addBook)
        self.layout.addWidget(self.books)
        self.addBook.add.clicked.connect(lambda b: self.books.update_list())

        self.setLayout(self.layout)


window = Window()
window.show()
app.exec()
