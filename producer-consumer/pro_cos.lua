local items = {1, "quit"}
-- local function consumer(x)
-- 	while true do
-- 		if x == "quit" then
-- 			break
-- 		end
-- 		print("cosumer: ", x)
-- 		x = coroutine.yield()
-- 	end
-- end

-- consumer = coroutine.create(consumer)

-- local function producer()
-- 	for _, item in ipairs(items) do
-- 		-- send to consumer
-- 		print("producer: ", item)
-- 		coroutine.resume(consumer, item)
-- 	end
-- end

-- -- producer drive the entire routine
-- producer()

local producer = coroutine.create(function()
	for _, v in ipairs(items) do
		print("producer: ", v)
		-- send to consumer
		coroutine.yield(v)
	end
end)

local function consumer()
	while true do
		local status, item = coroutine.resume(producer)
		if false == status or nil == item then
			break
		end
		print("consumer: ", item)
	end
end

-- consumber drive the entire routine
consumer()