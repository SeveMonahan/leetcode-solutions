WITH
    invalid_ips AS (
        SELECT
            ip
        FROM
            logs
        WHERE
                INET_ATON(ip) IS NULL
            OR
                ip NOT REGEXP '^[0-9]{1,3}(\\.[0-9]{1,3}){3}$'
            OR
                ip REGEXP '\\.0[0-9]'
            OR
                ip REGEXP '^0[0-9]'
    )
SELECT
    ip,
    COUNT(*) as invalid_count
FROM
    invalid_ips
GROUP BY
    ip
ORDER BY
    invalid_count DESC,
    ip DESC
