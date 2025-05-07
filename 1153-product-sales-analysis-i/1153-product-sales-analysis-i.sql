# Write your MySQL query statement below
select product_name,year,price from sales as a inner join product as b on a.product_id=b.product_id;