package com.zlup.lab3.problem4;

import java.util.Date;
import java.util.Vector;

public class Manager extends Employee {
    Vector<Employee> team = new Vector<>();
    private double bonus;

    public Manager(String name, double salary, Date hireDate, String insuranceNumber, double bonus) {
        super(name, salary, hireDate, insuranceNumber);
        this.bonus = bonus;
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    @Override
    public String toString() {
        return super.toString() + "\nBonus: " + this.bonus;
    }

    @Override
    public int compareTo(Employee other) {
        if (other instanceof Manager) {
            int res = super.compareTo(other);
            if (res == 0) return Double.compare(this.bonus, ((Manager) other).bonus);
            return res;
        }
        return super.compareTo(other);
    }

    @Override
    public Object clone() throws CloneNotSupportedException {
        Manager copy = (Manager) super.clone();
        copy.team = new Vector<>();
        for (Employee e : this.team) {
            copy.team.add((Employee) e.clone());
        }
        return copy;
    }


}
