public interface Queue<AnyType>
{
  int size();

  boolean isEmpty();

  AnyType first();

  void enqueue(AnyType newValue);

  AnyType dequeue();
}
