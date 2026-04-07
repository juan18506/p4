template <class T> class Manejador {
  private:
    std::vector<T *> collection;
    static Manejador<T> *instance;

  public:
    static Manejador<T> *getInstance();
};
