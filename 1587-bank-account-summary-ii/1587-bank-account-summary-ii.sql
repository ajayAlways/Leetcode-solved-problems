# Write your MySQL query statement below

SELECT t1.name, t2.balance FROM
Users t1 INNER JOIN
(SELECT account, SUM(amount) as balance
FROM Transactions
GROUP BY account) t2

ON t1.account=t2.account AND t2.balance>10000