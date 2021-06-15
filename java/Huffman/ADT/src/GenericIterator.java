import java.util.Iterator;

public class GenericIterator<T extends Comparable<T>> implements Iterator<T> {
    @Override
    public boolean hasNext() {
        return false;
    }

    @Override
    public T next() {
        return null;
    }
}
