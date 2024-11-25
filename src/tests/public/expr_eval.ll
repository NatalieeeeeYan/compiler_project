declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@TOKEN_NUM = global i32 0
@TOKEN_OTHER = global i32 1
@last_char = global i32 32
@num = global i32 0
@other = global i32 0
@cur_token = global i32 0
define i32 @next_char( ) {
bb1:
  %r100 = call i32 @getch()
  store i32 %r100, i32* @last_char
  %r101 = load i32, i32* @last_char
  ret i32 %r101
}

define i32 @is_space( i32 %r102 ) {
bb2:
  %r315 = add i32 0, 0
  %r316 = add i32 %r102, 0
  %r105 = icmp eq i32 %r316, 32
  br i1 %r105, label %bb_if_5_16_true, label %bb23_16_next

bb23_16_next:
  %r107 = icmp eq i32 %r316, 10
  br i1 %r107, label %bb_if_5_16_true, label %bb_if_5_16_false

bb_if_5_16_true:
  ret i32 1
bb_if_5_16_false:
  ret i32 0
}

define i32 @is_num( i32 %r108 ) {
bb3:
  %r318 = add i32 0, 0
  %r319 = add i32 %r108, 0
  %r111 = icmp sge i32 %r319, 48
  br i1 %r111, label %bb23_28_next, label %bb_if_5_28_false

bb23_28_next:
  %r113 = icmp sle i32 %r319, 57
  br i1 %r113, label %bb_if_5_28_true, label %bb_if_5_28_false

bb_if_5_28_true:
  ret i32 1
bb_if_5_28_false:
  ret i32 0
}

define i32 @next_token( ) {
bb4:
  br label %bb_while_5_40_cond

bb_while_5_40_cond:
  %r114 = load i32, i32* @last_char
  %r115 = call i32 @is_space(i32 %r114)
  %r116 = icmp ne i32 %r115, 0
  br i1 %r116, label %bb_while_5_40_whilestms, label %bb_while_5_40_bre

bb_while_5_40_whilestms:
  %r117 = call i32 @next_char()
  br label %bb_while_5_40_cond

bb_while_5_40_bre:
  %r118 = load i32, i32* @last_char
  %r119 = call i32 @is_num(i32 %r118)
  %r120 = icmp ne i32 %r119, 0
  br i1 %r120, label %bb_if_5_44_true, label %bb_if_5_44_false

bb_if_5_44_true:
  %r121 = load i32, i32* @last_char
  %r122 = sub i32 %r121, 48
  store i32 %r122, i32* @num
  br label %bb_while_9_47_cond

bb_while_9_47_cond:
  %r123 = call i32 @next_char()
  %r124 = call i32 @is_num(i32 %r123)
  %r125 = icmp ne i32 %r124, 0
  br i1 %r125, label %bb_while_9_47_whilestms, label %bb_while_9_47_bre

bb_while_9_47_whilestms:
  %r126 = load i32, i32* @num
  %r127 = mul i32 %r126, 10
  %r128 = load i32, i32* @last_char
  %r129 = add i32 %r127, %r128
  %r130 = sub i32 %r129, 48
  store i32 %r130, i32* @num
  br label %bb_while_9_47_cond

bb_while_9_47_bre:
  %r131 = load i32, i32* @TOKEN_NUM
  store i32 %r131, i32* @cur_token
  br label %bb_if_5_44_end

bb_if_5_44_false:
  %r132 = load i32, i32* @last_char
  store i32 %r132, i32* @other
  %r133 = call i32 @next_char()
  %r134 = load i32, i32* @TOKEN_OTHER
  store i32 %r134, i32* @cur_token
  br label %bb_if_5_44_end

bb_if_5_44_end:
  %r135 = load i32, i32* @cur_token
  ret i32 %r135
}

define i32 @panic( ) {
bb5:
  call void @putch(i32 112)
  call void @putch(i32 97)
  call void @putch(i32 110)
  call void @putch(i32 105)
  call void @putch(i32 99)
  call void @putch(i32 33)
  call void @putch(i32 10)
  ret i32 -1
}

define i32 @get_op_prec( i32 %r136 ) {
bb6:
  %r321 = add i32 0, 0
  %r322 = add i32 %r136, 0
  %r139 = icmp eq i32 %r322, 43
  br i1 %r139, label %bb_if_9_76_true, label %bb28_76_next

bb28_76_next:
  %r141 = icmp eq i32 %r322, 45
  br i1 %r141, label %bb_if_9_76_true, label %bb_if_9_76_false

bb_if_9_76_true:
  ret i32 10
bb_if_9_76_false:
  br label %bb_if_9_76_end

bb_if_9_76_end:
  %r143 = icmp eq i32 %r322, 42
  br i1 %r143, label %bb_if_9_78_true, label %bb28_78_next

bb28_78_next:
  %r145 = icmp eq i32 %r322, 47
  br i1 %r145, label %bb_if_9_78_true, label %bb42_78_next

bb42_78_next:
  %r147 = icmp eq i32 %r322, 37
  br i1 %r147, label %bb_if_9_78_true, label %bb_if_9_78_false

bb_if_9_78_true:
  ret i32 20
bb_if_9_78_false:
  br label %bb_if_9_78_end

bb_if_9_78_end:
  ret i32 0
}

define void @stack_push( i32* %r148, i32 %r149 ) {
bb7:
  %r325 = add i32 0, 0
  %r326 = add i32 %r149, 0
  %r151 = getelementptr i32, i32* %r148, i32 0
  %r152 = getelementptr i32, i32* %r148, i32 0
  %r153 = load i32, i32* %r152
  %r154 = add i32 %r153, 1
  store i32 %r154, i32* %r151
  %r327 = add i32 0, 0
  %r156 = getelementptr i32, i32* %r148, i32 0
  %r157 = load i32, i32* %r156
  %r328 = add i32 %r157, 0
  %r159 = getelementptr i32, i32* %r148, i32 %r328
  store i32 %r326, i32* %r159
  ret void
}

define i32 @stack_pop( i32* %r161 ) {
bb8:
  %r331 = add i32 0, 0
  %r163 = getelementptr i32, i32* %r161, i32 0
  %r164 = load i32, i32* %r163
  %r332 = add i32 %r164, 0
  %r333 = add i32 0, 0
  %r167 = getelementptr i32, i32* %r161, i32 %r332
  %r168 = load i32, i32* %r167
  %r334 = add i32 %r168, 0
  %r169 = getelementptr i32, i32* %r161, i32 0
  %r170 = getelementptr i32, i32* %r161, i32 0
  %r171 = load i32, i32* %r170
  %r172 = sub i32 %r171, 1
  store i32 %r172, i32* %r169
  ret i32 %r334
}

define i32 @stack_peek( i32* %r174 ) {
bb9:
  %r336 = add i32 0, 0
  %r176 = getelementptr i32, i32* %r174, i32 0
  %r177 = load i32, i32* %r176
  %r337 = add i32 %r177, 0
  %r179 = getelementptr i32, i32* %r174, i32 %r337
  %r180 = load i32, i32* %r179
  ret i32 %r180
}

define i32 @stack_size( i32* %r181 ) {
bb10:
  %r182 = getelementptr i32, i32* %r181, i32 0
  %r183 = load i32, i32* %r182
  ret i32 %r183
}

define i32 @mod( i32 %r184, i32 %r186 ) {
bb11:
  %r340 = add i32 0, 0
  %r341 = add i32 %r184, 0
  %r342 = add i32 0, 0
  %r343 = add i32 %r186, 0
  %r191 = sdiv i32 %r341, %r343
  %r193 = mul i32 %r191, %r343
  %r194 = sub i32 %r341, %r193
  ret i32 %r194
}

define i32 @eval_op( i32 %r195, i32 %r197, i32 %r199 ) {
bb12:
  %r347 = add i32 0, 0
  %r348 = add i32 %r195, 0
  %r349 = add i32 0, 0
  %r350 = add i32 %r197, 0
  %r351 = add i32 0, 0
  %r352 = add i32 %r199, 0
  %r202 = icmp eq i32 %r348, 43
  br i1 %r202, label %bb_if_9_116_true, label %bb_if_9_116_false

bb_if_9_116_true:
  %r205 = add i32 %r350, %r352
  ret i32 %r205
bb_if_9_116_false:
  br label %bb_if_9_116_end

bb_if_9_116_end:
  %r207 = icmp eq i32 %r348, 45
  br i1 %r207, label %bb_if_9_120_true, label %bb_if_9_120_false

bb_if_9_120_true:
  %r210 = sub i32 %r350, %r352
  ret i32 %r210
bb_if_9_120_false:
  br label %bb_if_9_120_end

bb_if_9_120_end:
  %r212 = icmp eq i32 %r348, 42
  br i1 %r212, label %bb_if_9_124_true, label %bb_if_9_124_false

bb_if_9_124_true:
  %r215 = mul i32 %r350, %r352
  ret i32 %r215
bb_if_9_124_false:
  br label %bb_if_9_124_end

bb_if_9_124_end:
  %r217 = icmp eq i32 %r348, 47
  br i1 %r217, label %bb_if_9_128_true, label %bb_if_9_128_false

bb_if_9_128_true:
  %r220 = sdiv i32 %r350, %r352
  ret i32 %r220
bb_if_9_128_false:
  br label %bb_if_9_128_end

bb_if_9_128_end:
  %r222 = icmp eq i32 %r348, 37
  br i1 %r222, label %bb_if_9_132_true, label %bb_if_9_132_false

bb_if_9_132_true:
  %r225 = call i32 @mod(i32 %r350, i32 %r352)
  ret i32 %r225
bb_if_9_132_false:
  br label %bb_if_9_132_end

bb_if_9_132_end:
  ret i32 0
}

define i32 @eval( ) {
bb13:
  %r361 = add i32 0, 0
  %r362 = add i32 0, 0
  %r363 = add i32 0, 0
  %r364 = add i32 0, 0
  %r365 = add i32 0, 0
  %r366 = add i32 0, 0
  %r367 = add i32 0, 0
  %r226 = alloca [ 256 x i32 ]
  %r227 = alloca [ 256 x i32 ]
  %r368 = add i32 0, 0
  %r369 = add i32 0, 0
  br label %bb_while_5_144_cond

bb_while_5_144_cond:
  %r370 = phi i32 [ %r369, %bb13 ], [ %r371, %bb_while_5_144_whilestms ]
  %r230 = icmp slt i32 %r370, 256
  br i1 %r230, label %bb_while_5_144_whilestms, label %bb_while_5_144_bre

bb_while_5_144_whilestms:
  %r232 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 %r370
  store i32 0, i32* %r232
  %r234 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 %r370
  store i32 0, i32* %r234
  %r236 = add i32 %r370, 1
  %r371 = add i32 %r236, 0
  br label %bb_while_5_144_cond

bb_while_5_144_bre:
  %r237 = load i32, i32* @cur_token
  %r238 = load i32, i32* @TOKEN_NUM
  %r239 = icmp ne i32 %r237, %r238
  br i1 %r239, label %bb_if_9_150_true, label %bb_if_9_150_false

bb_if_9_150_true:
  %r240 = call i32 @panic()
  ret i32 %r240
bb_if_9_150_false:
  br label %bb_if_9_150_end

bb_if_9_150_end:
  %r241 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r242 = load i32, i32* @num
  call void @stack_push(i32* %r241, i32 %r242)
  %r243 = call i32 @next_token()
  br label %bb_while_9_156_cond

bb_while_9_156_cond:
  %r372 = phi i32 [ %r366, %bb_if_9_150_end ], [ %r377, %bb_if_17_170_end ]
  %r373 = phi i32 [ %r365, %bb_if_9_150_end ], [ %r378, %bb_if_17_170_end ]
  %r374 = phi i32 [ %r364, %bb_if_9_150_end ], [ %r379, %bb_if_17_170_end ]
  %r375 = phi i32 [ %r367, %bb_if_9_150_end ], [ %r376, %bb_if_17_170_end ]
  %r244 = load i32, i32* @cur_token
  %r245 = load i32, i32* @TOKEN_OTHER
  %r246 = icmp eq i32 %r244, %r245
  br i1 %r246, label %bb_while_9_156_whilestms, label %bb_while_9_156_bre

bb_while_9_156_whilestms:
  %r248 = load i32, i32* @other
  %r376 = add i32 %r248, 0
  %r250 = call i32 @get_op_prec(i32 %r376)
  %r251 = icmp eq i32 %r250, 0
  br i1 %r251, label %bb_if_9_159_true, label %bb_if_9_159_false

bb_if_9_159_true:
  br label %bb_while_9_156_bre

bb_if_9_159_false:
  br label %bb_if_9_159_end

bb_if_9_159_end:
  %r252 = call i32 @next_token()
  br label %bb_while_17_162_cond

bb_while_17_162_cond:
  %r377 = phi i32 [ %r372, %bb_if_9_159_end ], [ %r380, %bb_while_17_162_whilestms ]
  %r378 = phi i32 [ %r373, %bb_if_9_159_end ], [ %r381, %bb_while_17_162_whilestms ]
  %r379 = phi i32 [ %r374, %bb_if_9_159_end ], [ %r382, %bb_while_17_162_whilestms ]
  %r253 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r254 = call i32 @stack_size(i32* %r253)
  %r255 = icmp ne i32 %r254, 0
  br i1 %r255, label %bb49_162_next, label %bb_while_17_162_bre

bb49_162_next:
  %r256 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r257 = call i32 @stack_peek(i32* %r256)
  %r258 = call i32 @get_op_prec(i32 %r257)
  %r260 = call i32 @get_op_prec(i32 %r376)
  %r261 = icmp sge i32 %r258, %r260
  br i1 %r261, label %bb_while_17_162_whilestms, label %bb_while_17_162_bre

bb_while_17_162_whilestms:
  %r263 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r264 = call i32 @stack_pop(i32* %r263)
  %r380 = add i32 %r264, 0
  %r266 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r267 = call i32 @stack_pop(i32* %r266)
  %r381 = add i32 %r267, 0
  %r269 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r270 = call i32 @stack_pop(i32* %r269)
  %r382 = add i32 %r270, 0
  %r271 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r275 = call i32 @eval_op(i32 %r380, i32 %r382, i32 %r381)
  call void @stack_push(i32* %r271, i32 %r275)
  br label %bb_while_17_162_cond

bb_while_17_162_bre:
  %r276 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  call void @stack_push(i32* %r276, i32 %r376)
  %r278 = load i32, i32* @cur_token
  %r279 = load i32, i32* @TOKEN_NUM
  %r280 = icmp ne i32 %r278, %r279
  br i1 %r280, label %bb_if_17_170_true, label %bb_if_17_170_false

bb_if_17_170_true:
  %r281 = call i32 @panic()
  ret i32 %r281
bb_if_17_170_false:
  br label %bb_if_17_170_end

bb_if_17_170_end:
  %r282 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r283 = load i32, i32* @num
  call void @stack_push(i32* %r282, i32 %r283)
  %r284 = call i32 @next_token()
  br label %bb_while_9_156_cond

bb_while_9_156_bre:
  %r383 = phi i32 [ %r375, %bb_while_9_156_cond ], [ %r376, %bb_if_9_159_true ]
  %r285 = call i32 @next_token()
  br label %bb_while_9_176_cond

bb_while_9_176_cond:
  %r384 = phi i32 [ %r363, %bb_while_9_156_bre ], [ %r387, %bb_while_9_176_whilestms ]
  %r385 = phi i32 [ %r362, %bb_while_9_156_bre ], [ %r388, %bb_while_9_176_whilestms ]
  %r386 = phi i32 [ %r361, %bb_while_9_156_bre ], [ %r389, %bb_while_9_176_whilestms ]
  %r286 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r287 = call i32 @stack_size(i32* %r286)
  %r288 = icmp ne i32 %r287, 0
  br i1 %r288, label %bb_while_9_176_whilestms, label %bb_while_9_176_bre

bb_while_9_176_whilestms:
  %r290 = getelementptr [256 x i32 ], [256 x i32 ]* %r227, i32 0, i32 0
  %r291 = call i32 @stack_pop(i32* %r290)
  %r387 = add i32 %r291, 0
  %r293 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r294 = call i32 @stack_pop(i32* %r293)
  %r388 = add i32 %r294, 0
  %r296 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r297 = call i32 @stack_pop(i32* %r296)
  %r389 = add i32 %r297, 0
  %r298 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r302 = call i32 @eval_op(i32 %r387, i32 %r389, i32 %r388)
  call void @stack_push(i32* %r298, i32 %r302)
  br label %bb_while_9_176_cond

bb_while_9_176_bre:
  %r303 = getelementptr [256 x i32 ], [256 x i32 ]* %r226, i32 0, i32 0
  %r304 = call i32 @stack_peek(i32* %r303)
  ret i32 %r304
}

define i32 @main( ) {
bb14:
  call void @_sysy_starttime(i32 205)
  %r391 = add i32 0, 0
  %r306 = call i32 @getint()
  %r392 = add i32 %r306, 0
  %r307 = call i32 @getch()
  %r308 = call i32 @next_token()
  br label %bb_while_5_192_cond

bb_while_5_192_cond:
  %r393 = phi i32 [ %r392, %bb14 ], [ %r394, %bb_while_5_192_whilestms ]
  %r310 = icmp ne i32 %r393, 0
  br i1 %r310, label %bb_while_5_192_whilestms, label %bb_while_5_192_bre

bb_while_5_192_whilestms:
  %r311 = call i32 @eval()
  call void @putint(i32 %r311)
  call void @putch(i32 10)
  %r313 = sub i32 %r393, 1
  %r394 = add i32 %r313, 0
  br label %bb_while_5_192_cond

bb_while_5_192_bre:
  call void @_sysy_stoptime(i32 214)
  ret i32 0
}

