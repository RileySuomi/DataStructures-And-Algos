-- Query a ride-hailing company database to analyze earnings by city. Your query should. 
-- 1. Calculate the total earnings as the sum of all ride fares for each city.
-- 2. Displaty city names alongside their corresponding total earnings.
-- 3. Sort resultes by earnings (ASC), then by city name (ASC)


SELECT 
    c.name,
    SUM(r.fare) AS total_earnings
FROM 
    CITIES c
JOIN 
    USERS u ON c.id = u.city_id
JOIN 
    RIDES r ON u.id = r.user_id
GROUP BY 
    c.name, c.id
ORDER BY 
    total_earnings ASC, c.name ASC;