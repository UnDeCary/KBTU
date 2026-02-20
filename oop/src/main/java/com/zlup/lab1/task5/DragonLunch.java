package com.zlup.lab1.task5;

import java.util.Vector;

public class DragonLunch {
    private Vector<Person> kidnapped;

    public DragonLunch() {
        kidnapped = new Vector<>();
    }

    public void kidnap(Person person) {
        if (
                !kidnapped.isEmpty() &&
                        kidnapped.lastElement().gender == Gender.BOY &&
                        person.gender == Gender.GIRL) {
            kidnapped.remove(kidnapped.lastElement());
            return;
        }

        kidnapped.add(person);
    }

    public boolean willDragonEatOrNot() {
        if (kidnapped.isEmpty()) {
            return false;
        }

        return true;
    }


    public boolean willDragonEatOrNot(String arg) {

    }
}
