# Write your MySQL query statement below
SELECT t1.user_id as buyer_id,t1.join_date,(CASE
WHEN t2.orders_in_2019 IS NOT NULL THEN t2.orders_in_2019
ELSE 0
END) as orders_in_2019
FROM Users t1
LEFT JOIN
(SELECT buyer_id as user_id, COUNT(buyer_id) as orders_in_2019
FROM Orders
WHERE YEAR(order_date)=2019
GROUP BY buyer_id
ORDER BY buyer_id) t2
ON t1.user_id=t2.user_id
    