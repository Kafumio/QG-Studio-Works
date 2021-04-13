package bean;

import java.util.Date;

/**
 * Copyright: Copyright (c) 2021 Asiainfo
 *
 * @ClassName: bean.Person
 * @Description: 数据库的表
 * @version: v1.0.0
 * @author: KafOto
 * @date: 2021/4/12
 * <p>
 * Modification History:
 * Date         Author          Version            Description
 * ------------------------------------------------------------
 * 2021/4/12      KafOto          v1.0.0               修改原因
 */
public class Person {
    private int id;
    private String name;
    private int age;
    private String address;
    private Date birth;

    public Person() { super(); }

    public Person(int id, String name, int age, String address, Date birth) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.address = address;
        this.birth = birth;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public Date getBirth() {
        return birth;
    }

    public void setBirth(Date birth) {
        this.birth = birth;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", address='" + address + '\'' +
                ", birth=" + birth +
                '}';
    }
}



