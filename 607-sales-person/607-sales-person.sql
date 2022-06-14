# Write your MySQL query statement below

SELECT name FROM SalesPerson
WHERE name NOT IN  (SELECT DISTINCT SalesPerson.name AS name
FROM SalesPerson, Company, Orders
WHERE SalesPerson.sales_id = Orders.sales_id AND Orders.com_id=Company.com_id AND Company.name="RED")