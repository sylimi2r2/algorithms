class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        int videoLen = stringToInt(video_len);
        int cur = stringToInt(pos);
        int opStart = stringToInt(op_start);
        int opEnd = stringToInt(op_end);

        cur = skipOp(cur, opStart, opEnd);
        for (String command: commands) {
            if (command.equals("prev")) {
                cur = Math.max(cur - 10, 0);
            } else if (command.equals("next")) {
                cur = Math.min(cur + 10, videoLen);
            }
            cur = skipOp(cur, opStart, opEnd);
        }

        return String.format("%02d:%02d", cur / 60, cur % 60);
    }

    int stringToInt(String pos) {
        String[] parts = pos.split(":");
        int minutes = Integer.parseInt(parts[0]);
        int seconds = Integer.parseInt(parts[1]);

        return minutes * 60 + seconds;
    }

    int skipOp(int time, int opStart, int opEnd) {
        if (time >= opStart && time < opEnd) {
            return opEnd;
        }
        return time;
    }
}