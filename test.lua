local taskbarflash = require('taskbarflash')

io.write("flashing in 3 seconds, unfocus this window"); io.flush()
local start, passed = os.time(), 0
while passed < 3 do
  if (os.time() - start) ~= passed then
  	io.write('.'); io.flush()
  	passed = os.time() - start
  end
end
print(" flashing")

taskbarflash()
