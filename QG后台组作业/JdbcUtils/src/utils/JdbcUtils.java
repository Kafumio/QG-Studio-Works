package utils;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileReader;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class JdbcUtils {
    private static DataSource ds = null;

    static {
        try {
            //读取资源文件，获取值
            //1.创建Properties集合类
            Properties pro = new Properties();
            //2.加载文件
            InputStream is = ClassLoader.getSystemClassLoader().getResourceAsStream("druid.properties");
            pro.load(is);
            ds = DruidDataSourceFactory.createDataSource(pro);
            //3.获取数据库连接池对象
            ds = DruidDataSourceFactory.createDataSource(pro);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
    *@Description: 获取数据库连接对象
    *@Param: void
    *@return: Connection ds.getConnection()
    *@Author: KafOto
    *@throws: Exception
    *@date: 2021/4/12
    */
    public static Connection getConnection() throws Exception {
        return ds.getConnection();
    }

    /**
    *@Description: 关闭资源
    *@Param: ResultSet rs, Statement stmt, Connection conn
    *@return: void
    *@Author: KafOto
    *@throws:
    *@date: 2021/4/12
    */
    public static void close(ResultSet rs, Statement stmt, Connection conn) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if (stmt != null) {
            try {
                stmt.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }

    }

    //close()方法重载，用于在非查询操作后释放资源
    public static void close( Statement stmt, Connection conn) {
        close(null,stmt,conn);
    }

    /**
    *@Description: 获取数据库连接池对象
    *@Param: void
    *@return: DataSource ds
    *@Author: KafOto
    *@throws: Exception
    *@date: 2021/4/12
    */
    public static DataSource getDataSource(){
        return ds;
    }
}
