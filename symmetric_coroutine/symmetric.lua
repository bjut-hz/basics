local symmetric = {}

symmetric.main = function () end
symmetric.current = symmetric.main

function symmetric.set_main(f) 
    symmetric.main = f
    symmetric.current = f
end

-- f接收一个参数
function symmetric.create(f)
    return coroutine.wrap(function (val)
        return nil, f(val)
    end)
end

-- 在主协程里做分配
function symmetric.transfer(co, val)
    if symmetric.current ~= symmetric.main then
        -- 非主协程yeild到主协程后再做调用, 把协程本身作为yield的参数带回主协程,主协程接收后继续分配
       return coroutine.yield(co, val)
    else
        while co do
            print(co)
            symmetric.current = co
            if co == symmetric.main then
                return val
            end

            co, val = co(val)
        end

        error("no dispatched coroutine")
    end
end


return symmetric