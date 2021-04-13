package dao;

import bean.Person;

import java.sql.Connection;
import java.sql.Date;
import java.util.List;

/**
 * @author KafOto
 */
public interface PersonDAO {
    /**
    *@Description: 将per对象添加到数据库中
    *@Param: Connection conn, Person per
    *@Author: KafOto
    *@date: 2021/4/12
    */
    void insert(Connection conn, Person per);

    /**
    *@Description: 针对指定的id，删除表中的一条记录
    *@Param: Connection conn,int id
    *@Author: KafOto
    *@date: 2021/4/12
    */
    void deleteById(Connection conn,int id);

    /**
    *@Description: 针对内存中的per对象，去修改数据表中指定的记录
    *@Param: Connection conn,Person per
    *@Author: KafOto
    *@date: 2021/4/12
    */
    void update(Connection conn,Person per);

    /**
    *@Description: 针对指定的id查询得到对应的Person对象
    *@Param: Connection conn,int id
    *@Author: KafOto
    *@return: Person对象
    *@date: 2021/4/12
    */
    Person getPersonById(Connection conn,int id);

    /**
     *@Description: 针对指定的名字查询得到对应的Person对象
     *@Param: Connection conn,String name
     *@Author: KafOto
     *@return: Person对象
     *@date: 2021/4/12
     */
    Person getPersonByName(Connection conn,String name);

    /**
     *@Description: 通过address查询得到对应的Person对象集合
     *@Param: Connection conn,String address
     *@Author: KafOto
     *@return: Person对象集合
     *@date: 2021/4/12
     */
    List<Person> getPersonByAdd(Connection conn,String address);

    /**
     *@Description: 通过age查询得到对应的Person对象集合
     *@Param: Connection conn,int age
     *@Author: KafOto
     *@return: Person对象集合
     *@date: 2021/4/12
     */
    List<Person> getPersonByAge(Connection conn,int age);

    /**
     *@Description: 查询表中的所有记录构成的集合
     *@Param: Connection conn
     *@Author: KafOto
     *@return: Person对象集合
     *@date: 2021/4/12
     */
    List<Person> getAll(Connection conn);

    /**
    *@Description: 返回数据表中的数据的条目数
    *@Param: Connection conn
    *@Author: KafOto
    *@date: 2021/4/12
    */
    Long getCount(Connection conn);

    /**
    *@Description: 返回数据表中年龄最大的Person对象
    *@Param: Connection conn
    *@Author: KafOto
    *@return: int
    *@date: 2021/4/12
    */
    int getMaxAge(Connection conn);

    /**
     *@Description: 返回数据表中年龄最小的Person对象
     *@Param: Connection conn
     *@Author: KafOto
     *@return: int
     *@date: 2021/4/12
     */
    int getMinAge(Connection conn);
}
