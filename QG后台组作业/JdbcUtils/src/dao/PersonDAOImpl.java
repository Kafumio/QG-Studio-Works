package dao;

import bean.Person;

import java.sql.Connection;
import java.util.List;

/**
 * Copyright: Copyright (c) 2021 Asiainfo
 *
 * @ClassName: dao.PersonDaoImpl
 * @Description: PersonDao的实现类，实现数据操控方法
 * @version: v1.0.0
 * @author: KafOto
 * @date: 2021/4/12
 * <p>
 * Modification History:
 * Date         Author          Version            Description
 * ------------------------------------------------------------
 * 2021/4/12      KafOto          v1.0.0               修改原因
 */
public class PersonDAOImpl extends BaseDAO implements PersonDAO {
    @Override
    public void insert(Connection conn, Person per) {
        String sql = "insert into person(name,age,address,birth) values(?,?,?,?)";
        update(conn,sql,per.getName(),per.getAge(),per.getAddress(),per.getBirth());
    }

    @Override
    public void deleteById(Connection conn, int id) {
        String sql = "delete from person where id = ?";
        int update = update(conn, sql, id);
        if (update > 0){
            System.out.println("删除成功");
        }else{
            System.out.println("删除失败");
        }
    }

    @Override
    public void update(Connection conn, Person per) {
        String sql = "update person set name = ?,age = ?,address = ?,birth = ? where id = ?";
        int update = update(conn, sql, per.getName(), per.getAge(), per.getAddress(), per.getBirth(), per.getId());
        if (update > 0){
            System.out.println("修改成功");
        }else{
            System.out.println("修改失败");
        }
    }

    @Override
    public Person getPersonById(Connection conn,int id) {
        String sql = "select id,name,age,address,birth from person where id = ?";
        Person person = getInstance(conn,Person.class,sql,id);
        if (person != null){
            System.out.println("通过id获取数据成功");
        }else{
            System.out.println("通过id获取数据失败");
        }
        return person;
    }

    @Override
    public Person getPersonByName(Connection conn,String name) {
        String sql = "select id,name,age,address,birth from person where name = ?";
        Person person = getInstance(conn,Person.class,sql,name);
        if (person != null){
            System.out.println("通过名字获取数据成功");
        }else{
            System.out.println("通过名字获取数据失败");
        }
        return person;
    }

    @Override
    public List<Person> getPersonByAdd(Connection conn,String address) {
        String sql = "select id,name,age,address,birth from person where address = ?";
        List<Person> list = getForList(conn,Person.class,sql,address);
        if (list != null){
            System.out.println("通过地址获取数据成功");
        }else {
            System.out.println("通过地址获取数据失败");
        }
        return list;
    }

    @Override
    public List<Person> getPersonByAge(Connection conn,int age) {
        String sql = "select id,name,age,address,birth from person where age = ?";
        List<Person> list = getForList(conn,Person.class,sql,age);
        if (list != null){
            System.out.println("通过年龄获取数据成功");
        }else {
            System.out.println("通过年龄获取数据失败");
        }
        return list;
    }

    @Override
    public List<Person> getAll(Connection conn) {
        String sql = "select * from person";
        List<Person> list = getForList(conn,Person.class,sql);
        if (list != null){
            System.out.println("获取所有数据成功");
        }else {
            System.out.println("获取所有数据失败");
        }
        return list;
    }

    @Override
    public Long getCount(Connection conn) {
        String sql = "select count(*) from person";
        System.out.println("获取条目数成功");
        return getValue(conn,sql);
    }

    @Override
    public int getMaxAge(Connection conn) {
        String sql = "select max(age) from person";
        return getValue(conn,sql);
    }

    @Override
    public int getMinAge(Connection conn) {
        String sql = "select min(age) from person";
        return getValue(conn,sql);
    }
}



