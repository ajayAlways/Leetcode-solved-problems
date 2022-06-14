# Write your MySQL query statement below

SELECT t1.customer_number 
FROM (SELECT customer_number, COUNT(customer_number) as num_orders
FROM Orders
GROUP BY customer_number
ORDER BY num_orders DESC) t1
LIMIT 1