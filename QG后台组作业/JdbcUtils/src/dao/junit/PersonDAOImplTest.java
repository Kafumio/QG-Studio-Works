package dao.junit;

import bean.Person;
import dao.PersonDAOImpl;
import org.junit.jupiter.api.Test;
import utils.JdbcUtils;

import java.sql.Connection;
import java.sql.Date;
import java.text.SimpleDateFormat;
import java.util.List;

/**
 * Copyright: Copyright (c) 2021 Asiainfo
 *
 * @ClassName: dao.junit.PersonDAOImplTest
 * @Description: PersonDAOImpl的测试类，测试是否成功实现数据操作功能
 * @version: v1.0.0
 * @author: KafOto
 * @date: 2021/4/12
 * <p>
 * Modification History:
 * Date         Author          Version            Description
 * ------------------------------------------------------------
 * 2021/4/12      KafOto          v1.0.0               修改原因
 */
public class PersonDAOImplTest {
    private PersonDAOImpl dao = new PersonDAOImpl();

    @Test
    public void testInsert(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            Person per = new Person(2,"翔哥",18,"中山",new SimpleDateFormat("yyyy-MM-dd").parse("2002-08-25"));
            dao.insert(conn,per);
            System.out.println("插入成功");
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testDeleteById(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            dao.deleteById(conn,3);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testUpdate(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            Person person = new Person(4,"秘鱼",18,"湖南",new SimpleDateFormat("yyyy-MM-dd").parse("2003-01-17"));
            dao.update(conn,person);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testGetPersonById(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            Person personById = dao.getPersonById(conn, 4);
            System.out.println(personById);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testGetPersonByName(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            System.out.println(dao.getPersonByName(conn,"浩林"));
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testGetPersonByAge(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            System.out.println(dao.getPersonByAge(conn,18));
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testGetPersonByAdd(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            System.out.println(dao.getPersonByAdd(conn,"中山"));
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testGetAll(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            List<Person> all = dao.getAll(conn);
            System.out.println(all);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testGetCount(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            Long count = dao.getCount(conn);
            System.out.println("条目数为" + count);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testgetMaxAge(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            int maxAge = dao.getMaxAge(conn);
            System.out.println("年龄最大为" + maxAge);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }

    @Test
    public void testMinAge(){
        Connection conn = null;
        try {
            conn = JdbcUtils.getConnection();
            int minAge = dao.getMinAge(conn);
            System.out.println("年龄最小为：" + minAge);
        } catch (Exception e) {
            e.printStackTrace();
        }finally {
            JdbcUtils.close(null,conn);
        }
    }
}



