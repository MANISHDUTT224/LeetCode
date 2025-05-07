# Write your MySQL query statement below
select customer_id,count(*) as count_no_trans from visits as a left join transactions as b on a.visit_id=b.visit_id where b.transaction_id is null group by 1;