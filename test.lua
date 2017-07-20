local taskbarflash = require('taskbarflash')

local function sleep(n)
  os.execute("sleep " .. tonumber(n))
end

sleep(2)
taskbarflash(3)
sleep(2)