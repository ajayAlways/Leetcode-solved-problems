# Write your MySQL query statement below

SELECT email FROM (SELECT email,COUNT(email) AS email_count
FROM Person
GROUP BY email) t1
WHERE t1.email_count>1

