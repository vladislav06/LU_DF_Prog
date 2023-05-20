template <typename T> class List {
private:
  struct Element {
    T data;
    Element *next;
    Element(T data, Element *next) : data(data), next(next) {}
    Element(){};
  };
  Element *head = nullptr;

public:
  List();
  ~List();

  void push_back(T data);
  void push_front(T data);

  int find(T data);

  T getAt(int i);
  T operator[](int i);
};
