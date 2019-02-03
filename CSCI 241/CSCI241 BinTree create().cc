template <class T>
void BinTree<T>::create(BinTNode<T> * source, BinTNode<T> *& dest)
  {
  if ( source != 0)
    {
	dest = new BinTNode(source->data)
	create(source->leftchild, dest->leftchild)
	create(source->rightchild, dest->rightchild)
	}
  }