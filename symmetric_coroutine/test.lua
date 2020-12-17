local symmetric = require "symmetric"

local co1
local co2

co1 = symmetric.create(function (n)
    print("1: co1 received value "..n)
    n = symmetric.transfer(co2,n + 10)
    print("2: co1 received value "..n)
    n = symmetric.transfer(symmetric.main,n + 10)
    print("3: co1 received value "..n)
    -- 在对称式模型下，每一个协程(当然主协程出外)最后都必须显式地将控制权传递给其它的协程
    symmetric.transfer(symmetric.main, n + 10)
end)

co2 = symmetric.create(function (n)
    print("1: co2 received value "..n)
    n = symmetric.transfer(symmetric.main,n + 10)
    print("2: co2 received value "..n)
    symmetric.transfer(co1,n + 10)
end)



local function main()
    local n = symmetric.transfer(co1,0)
    print("1: main received value "..n)
    n = symmetric.transfer(co2,n + 10)
    print("2: main received value "..n)
    n = symmetric.transfer(co1,n + 10)
    print("3: main received value "..n)
end

symmetric.set_main(main)

print("co1", co1)
print("co2", co2)
print("main", main)

main()