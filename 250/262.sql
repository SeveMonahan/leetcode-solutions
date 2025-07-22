WITH
    innocent_users AS (
        SELECT users_id FROM Users WHERE banned = 'No'
    ),
    innocent_trips AS (
        SELECT request_at, status
        FROM Trips
        WHERE client_id IN (SELECT users_id FROM innocent_users)
          AND driver_id IN (SELECT users_id FROM innocent_users)
    ),
    daily_stats AS (
        SELECT
            request_at AS Day,
            SUM(CASE WHEN status = 'completed' THEN 0 ELSE 1 END) AS num_cancelled,
            COUNT(*) AS num_total
        FROM innocent_trips
        GROUP BY request_at
    )
SELECT
    Day,
    ROUND(1.0 * num_cancelled / num_total, 2) AS 'Cancellation Rate'
FROM daily_stats
WHERE Day BETWEEN "2013-10-01" AND "2013-10-03"
