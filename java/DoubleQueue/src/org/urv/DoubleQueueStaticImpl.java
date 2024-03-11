package org.urv;

public class DoubleQueueStaticImpl<T> implements DoubleQueue<T> {

    private T[] arr;
    private int midaArray = 10;
    private int numElems;


    public DoubleQueueStaticImpl() {
        arr = (T[]) new Object[this.midaArray];
        this.numElems = 0;
    }

    @Override
    public void addTop(T t) {

    }


    @Override
    public void addBottom(T t) {
        if (this.esPlena())
        {
            this
        }
        this.arr[this.numElems] = t;
        this.numElems++;
    }

    private void redimensionar()
    {
        this.midaArray = this.midaArray * 2;
        T[] newArray = (T[]) new Object[this.midaArray];
    }

    private boolean esPlena()
    {
        return this.numElems == this.midaArray;
    }



    @Override
    public T popTop() {
        return null;
    }

    @Override
    public T popBottom() {
        return null;
    }

    @Override
    public T top() {
        return null;
    }

    @Override
    public T bottom() {
        return null;
    }
}
