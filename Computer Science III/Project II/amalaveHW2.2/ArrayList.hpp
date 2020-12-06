#ifndef ARRAY_LIST
#define ARRAY_LIST

#include "List.hpp"

template <class item_t>
class ArrayList : public List<item_t>
{
  protected:
   item_t* items;
   int size;
   int capacity;

   //must protected/private methods also be virtual?
   virtual void doubleCapacity();
   virtual void variablePush(int index);
   virtual void variablePop(int index);
   
  public:
   ArrayList();
   ArrayList(int capacity);
   virtual ~ArrayList();

   virtual void pushBack(const item_t& item);   
   virtual void popBack();
   
   virtual const item_t& getBack() const;
   
   virtual void pushFront(const item_t& item);
   virtual void popFront();

   virtual const item_t& getFront() const;
   virtual const item_t& getItem(int index) const;

   virtual void setItem(int index, const item_t& item);
   virtual void insert(int index, const item_t& item);
   virtual void remove(int index);
   
   virtual int getSize() const;
   
   virtual bool isEmpty() const;
   
   virtual int getCapacity() const;
};

#include "ArrayList.tpp"

#endif
