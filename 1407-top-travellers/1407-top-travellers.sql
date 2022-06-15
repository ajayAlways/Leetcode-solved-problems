# Write your MySQL query statement below

SELECT name,IFNULL(SUM(distance),0) as travelled_distance
FROM Users t1
LEFT JOIN
Rides t2
ON t1.id=t2.user_id
GROUP BY user_id
ORDER BY travelled_distance DESC, name ASC