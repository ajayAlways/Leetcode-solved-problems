# Write your MySQL query statement below
SELECT t1.user_id as buyer_id,t1.join_date,
IFNULL(COUNT(order_id),0) as orders_in_2019
FROM Users t1
LEFT JOIN
Orders t2
ON t1.user_id=t2.buyer_id
AND YEAR(t2.order_date)='2019'
GROUP BY t1.user_id
    