package org.urv;

public interface DoubleQueue<T> {

    void addTop(T t);

    void addBottom(T t);

    T popTop() throws Exception;

    T popBottom() throws Exception;

    T top();

    T bottom();

}
