package com.zlup.lab3.problem4;

import java.util.Collections;
import java.util.Date;
import java.util.Vector;

public class Main {
    public static void main(String[] args) throws CloneNotSupportedException {
        Vector<Employee> staff = new Vector<>();
        staff.add(new Employee("Ilya",  1000000, new Date(1), "123"));
        staff.add(new Employee("Yussuf",  2000000, new Date(2), "523"));
        staff.add(new Manager("Vadim",  3000000, new Date(3), "343", 20000));

        Collections.sort(staff);
        System.out.println(staff);

        staff.sort(new NameComparator());
        System.out.println(staff);

        staff.sort(new DateComparator());
        System.out.println(staff);

        Manager manager1 = new Manager("Daniel", 3000000, new Date(5), "234", 20000);
        Manager manager2 = (Manager) manager1.clone();
    }
}
