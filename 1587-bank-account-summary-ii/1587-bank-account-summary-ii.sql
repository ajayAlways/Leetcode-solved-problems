# Write your MySQL query statement below

SELECT name,SUM(amount) as balance
FROM Users
LEFT JOIN Transactions
USING(account)
GROUP BY account
HAVING SUM(amount)>10000