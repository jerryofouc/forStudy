import sys
import json
for line in sys.stdin:
	line = json.loads(line)
	print json.dumps(line,ensure_ascii=False,sort_keys=True)
	

