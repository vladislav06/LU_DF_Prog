# Gramatnecbas inventara parvaldibas sistema

# Global book dict
books = {
    9781234567897: {"title": "", "author": "", "isbn": 9781234567897, "price": 10.0, "stock": 1}
}


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
