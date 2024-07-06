#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

// for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "user"; // �����ͺ��̽� �����
const string password = "1234"; // �����ͺ��̽� ���� ��й�ȣ

int main()
{
  // MySQL Connector/C++ �ʱ�ȭ
  sql::Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
  sql::Connection* con;
  sql::Statement* stmt;
  sql::PreparedStatement* pstmt;
  sql::ResultSet* result;

  try
  {
    driver = get_driver_instance();
    con = driver->connect(server, username, password);
  }
  catch (sql::SQLException e)
  {
    cout << "Could not connect to server. Error message: " << e.what() << endl;
    system("pause");
    exit(1);
  }

  // please create database "cpp_db" ahead of time
  con->setSchema("cpp_db");

  // �����ͺ��̽� ���� ����
  stmt = con->createStatement();
  stmt->execute("DROP TABLE IF EXISTS inventory");
  cout << "Finished dropping table (if existed)" << endl;
  stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
  cout << "Finished creating table" << endl;
  delete stmt;

  pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
  pstmt->setString(1, "banana");
  pstmt->setInt(2, 150);
  pstmt->execute();
  cout << "One row(banana) inserted." << endl;

  pstmt->setString(1, "orange");
  pstmt->setInt(2, 154);
  pstmt->execute();
  cout << "One row(orange) inserted." << endl;

  pstmt->setString(1, "apple");
  pstmt->setInt(2, 100);
  pstmt->execute();
  cout << "One row(apple) inserted." << endl;

  pstmt->setString(1, "grape");
  pstmt->setInt(2, 300);
  pstmt->execute();
  cout << "One row(grape) inserted." << endl;

  // ������Ʈ
  pstmt = con->prepareStatement("UPDATE inventory SET quantity = ? WHERE name = ?");
  pstmt->setInt(1, 200);
  pstmt->setString(2, "banana");
  pstmt->executeQuery();
  printf("banana updated\n");

  // ����
  pstmt = con->prepareStatement("DELETE FROM inventory WHERE name = ?");
  pstmt->setString(1, "apple");
  result = pstmt->executeQuery();
  printf("apple deleted\n");


  // MySQL Connector/C++ ����
  delete pstmt;
  delete con;
  system("pause");
  return 0;
}