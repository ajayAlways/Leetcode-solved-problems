# Write your MySQL query statement below
SELECT s1.stock_name,(s1.price-s2.price) as capital_gain_loss
FROM (SELECT stock_name,operation,SUM(price) as price
FROM Stocks
GROUP BY stock_name,operation) s1
JOIN
(SELECT stock_name,operation,SUM(price) as price
FROM Stocks
GROUP BY stock_name,operation) s2

ON s1.stock_name=s2.stock_name AND s1.operation='Sell' AND s2.operation='Buy'