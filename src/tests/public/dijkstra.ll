declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@INF = global i32 65535
%array2D = type { [16 x i32 ] }
@e = global [ 16 x %array2D ] zeroinitializer
@book = global [ 16 x i32 ] zeroinitializer
@dis = global [ 16 x i32 ] zeroinitializer
@n = global i32 0
@m = global i32 0
@v1 = global i32 0
@v2 = global i32 0
@w = global i32 0
define void @Dijkstra( ) {
bb1:
  %r242 = add i32 0, 0
  %r243 = add i32 0, 0
  %r244 = add i32 0, 0
  %r245 = add i32 0, 0
  %r246 = add i32 0, 0
  %r247 = add i32 1, 0
  br label %bb_while_5_18_cond

bb_while_5_18_cond:
  %r248 = phi i32 [ %r247, %bb1 ], [ %r249, %bb_while_5_18_whilestms ]
  %r102 = load i32, i32* @n
  %r103 = icmp sle i32 %r248, %r102
  br i1 %r103, label %bb_while_5_18_whilestms, label %bb_while_5_18_bre

bb_while_5_18_whilestms:
  %r105 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r248
  %r106 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 1
  %r107 = getelementptr %array2D, %array2D* %r106, i32 0, i32 0
  %r109 = getelementptr [16 x i32 ], [16 x i32 ]* %r107, i32 0, i32 %r248
  %r110 = load i32, i32* %r109
  store i32 %r110, i32* %r105
  %r112 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r248
  store i32 0, i32* %r112
  %r114 = add i32 %r248, 1
  %r249 = add i32 %r114, 0
  br label %bb_while_5_18_cond

bb_while_5_18_bre:
  %r115 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 1
  store i32 1, i32* %r115
  %r250 = add i32 1, 0
  br label %bb_while_5_26_cond

bb_while_5_26_cond:
  %r251 = phi i32 [ %r250, %bb_while_5_18_bre ], [ %r270, %bb_while_9_39_bre ]
  %r252 = phi i32 [ %r243, %bb_while_5_18_bre ], [ %r259, %bb_while_9_39_bre ]
  %r253 = phi i32 [ %r242, %bb_while_5_18_bre ], [ %r268, %bb_while_9_39_bre ]
  %r254 = phi i32 [ %r245, %bb_while_5_18_bre ], [ %r260, %bb_while_9_39_bre ]
  %r255 = phi i32 [ %r244, %bb_while_5_18_bre ], [ %r261, %bb_while_9_39_bre ]
  %r117 = load i32, i32* @n
  %r118 = sub i32 %r117, 1
  %r119 = icmp sle i32 %r251, %r118
  br i1 %r119, label %bb_while_5_26_whilestms, label %bb_while_5_26_bre

bb_while_5_26_whilestms:
  %r121 = load i32, i32* @INF
  %r256 = add i32 %r121, 0
  %r257 = add i32 0, 0
  %r258 = add i32 1, 0
  br label %bb_while_9_30_cond

bb_while_9_30_cond:
  %r259 = phi i32 [ %r258, %bb_while_5_26_whilestms ], [ %r266, %bb_if_13_31_end ]
  %r260 = phi i32 [ %r256, %bb_while_5_26_whilestms ], [ %r264, %bb_if_13_31_end ]
  %r261 = phi i32 [ %r257, %bb_while_5_26_whilestms ], [ %r265, %bb_if_13_31_end ]
  %r125 = load i32, i32* @n
  %r126 = icmp sle i32 %r259, %r125
  br i1 %r126, label %bb_while_9_30_whilestms, label %bb_while_9_30_bre

bb_while_9_30_whilestms:
  %r129 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r259
  %r130 = load i32, i32* %r129
  %r131 = icmp sgt i32 %r260, %r130
  br i1 %r131, label %bb40_31_next, label %bb_if_13_31_false

bb40_31_next:
  %r133 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r259
  %r134 = load i32, i32* %r133
  %r135 = icmp eq i32 %r134, 0
  br i1 %r135, label %bb_if_13_31_true, label %bb_if_13_31_false

bb_if_13_31_true:
  %r137 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r259
  %r138 = load i32, i32* %r137
  %r262 = add i32 %r138, 0
  %r263 = add i32 %r259, 0
  br label %bb_if_13_31_end

bb_if_13_31_false:
  br label %bb_if_13_31_end

bb_if_13_31_end:
  %r264 = phi i32 [ %r262, %bb_if_13_31_true ], [ %r260, %bb_if_13_31_false ]
  %r265 = phi i32 [ %r263, %bb_if_13_31_true ], [ %r261, %bb_if_13_31_false ]
  %r141 = add i32 %r259, 1
  %r266 = add i32 %r141, 0
  br label %bb_while_9_30_cond

bb_while_9_30_bre:
  %r143 = getelementptr [16 x i32 ], [16 x i32 ]* @book, i32 0, i32 %r261
  store i32 1, i32* %r143
  %r267 = add i32 1, 0
  br label %bb_while_9_39_cond

bb_while_9_39_cond:
  %r268 = phi i32 [ %r267, %bb_while_9_30_bre ], [ %r269, %bb_if_13_40_end ]
  %r146 = load i32, i32* @n
  %r147 = icmp sle i32 %r268, %r146
  br i1 %r147, label %bb_while_9_39_whilestms, label %bb_while_9_39_bre

bb_while_9_39_whilestms:
  %r149 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r261
  %r150 = getelementptr %array2D, %array2D* %r149, i32 0, i32 0
  %r152 = getelementptr [16 x i32 ], [16 x i32 ]* %r150, i32 0, i32 %r268
  %r153 = load i32, i32* %r152
  %r154 = load i32, i32* @INF
  %r155 = icmp slt i32 %r153, %r154
  br i1 %r155, label %bb_if_13_40_true, label %bb_if_13_40_false

bb_if_13_40_true:
  %r157 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r268
  %r158 = load i32, i32* %r157
  %r160 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r261
  %r161 = load i32, i32* %r160
  %r163 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r261
  %r164 = getelementptr %array2D, %array2D* %r163, i32 0, i32 0
  %r166 = getelementptr [16 x i32 ], [16 x i32 ]* %r164, i32 0, i32 %r268
  %r167 = load i32, i32* %r166
  %r168 = add i32 %r161, %r167
  %r169 = icmp sgt i32 %r158, %r168
  br i1 %r169, label %bb_if_17_41_true, label %bb_if_17_41_false

bb_if_17_41_true:
  %r171 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r268
  %r173 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r261
  %r174 = load i32, i32* %r173
  %r176 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r261
  %r177 = getelementptr %array2D, %array2D* %r176, i32 0, i32 0
  %r179 = getelementptr [16 x i32 ], [16 x i32 ]* %r177, i32 0, i32 %r268
  %r180 = load i32, i32* %r179
  %r181 = add i32 %r174, %r180
  store i32 %r181, i32* %r171
  br label %bb_if_17_41_end

bb_if_17_41_false:
  br label %bb_if_17_41_end

bb_if_17_41_end:
  br label %bb_if_13_40_end

bb_if_13_40_false:
  br label %bb_if_13_40_end

bb_if_13_40_end:
  %r183 = add i32 %r268, 1
  %r269 = add i32 %r183, 0
  br label %bb_while_9_39_cond

bb_while_9_39_bre:
  %r185 = add i32 %r251, 1
  %r270 = add i32 %r185, 0
  br label %bb_while_5_26_cond

bb_while_5_26_bre:
  ret void
}

define i32 @main( ) {
bb2:
  %r275 = add i32 0, 0
  %r276 = add i32 0, 0
  %r277 = add i32 0, 0
  call void @_sysy_starttime(i32 53)
  %r278 = add i32 0, 0
  %r187 = call i32 @getint()
  store i32 %r187, i32* @n
  %r188 = call i32 @getint()
  store i32 %r188, i32* @m
  %r279 = add i32 1, 0
  br label %bb_while_5_59_cond

bb_while_5_59_cond:
  %r280 = phi i32 [ %r279, %bb2 ], [ %r285, %bb_while_9_61_bre ]
  %r281 = phi i32 [ %r277, %bb2 ], [ %r283, %bb_while_9_61_bre ]
  %r190 = load i32, i32* @n
  %r191 = icmp sle i32 %r280, %r190
  br i1 %r191, label %bb_while_5_59_whilestms, label %bb_while_5_59_bre

bb_while_5_59_whilestms:
  %r282 = add i32 1, 0
  br label %bb_while_9_61_cond

bb_while_9_61_cond:
  %r283 = phi i32 [ %r282, %bb_while_5_59_whilestms ], [ %r284, %bb_if_13_62_end ]
  %r194 = load i32, i32* @n
  %r195 = icmp sle i32 %r283, %r194
  br i1 %r195, label %bb_while_9_61_whilestms, label %bb_while_9_61_bre

bb_while_9_61_whilestms:
  %r198 = icmp eq i32 %r280, %r283
  br i1 %r198, label %bb_if_13_62_true, label %bb_if_13_62_false

bb_if_13_62_true:
  %r200 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r280
  %r201 = getelementptr %array2D, %array2D* %r200, i32 0, i32 0
  %r203 = getelementptr [16 x i32 ], [16 x i32 ]* %r201, i32 0, i32 %r283
  store i32 0, i32* %r203
  br label %bb_if_13_62_end

bb_if_13_62_false:
  %r205 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r280
  %r206 = getelementptr %array2D, %array2D* %r205, i32 0, i32 0
  %r208 = getelementptr [16 x i32 ], [16 x i32 ]* %r206, i32 0, i32 %r283
  %r209 = load i32, i32* @INF
  store i32 %r209, i32* %r208
  br label %bb_if_13_62_end

bb_if_13_62_end:
  %r211 = add i32 %r283, 1
  %r284 = add i32 %r211, 0
  br label %bb_while_9_61_cond

bb_while_9_61_bre:
  %r213 = add i32 %r280, 1
  %r285 = add i32 %r213, 0
  br label %bb_while_5_59_cond

bb_while_5_59_bre:
  %r286 = add i32 1, 0
  br label %bb_while_5_76_cond

bb_while_5_76_cond:
  %r287 = phi i32 [ %r286, %bb_while_5_59_bre ], [ %r292, %bb_while_5_76_whilestms ]
  %r288 = phi i32 [ %r276, %bb_while_5_59_bre ], [ %r290, %bb_while_5_76_whilestms ]
  %r289 = phi i32 [ %r275, %bb_while_5_59_bre ], [ %r291, %bb_while_5_76_whilestms ]
  %r215 = load i32, i32* @m
  %r216 = icmp sle i32 %r287, %r215
  br i1 %r216, label %bb_while_5_76_whilestms, label %bb_while_5_76_bre

bb_while_5_76_whilestms:
  %r218 = call i32 @getint()
  %r290 = add i32 %r218, 0
  %r220 = call i32 @getint()
  %r291 = add i32 %r220, 0
  %r222 = getelementptr [16 x %array2D ], [16 x %array2D ]* @e, i32 0, i32 %r290
  %r223 = getelementptr %array2D, %array2D* %r222, i32 0, i32 0
  %r225 = getelementptr [16 x i32 ], [16 x i32 ]* %r223, i32 0, i32 %r291
  %r226 = call i32 @getint()
  store i32 %r226, i32* %r225
  %r228 = add i32 %r287, 1
  %r292 = add i32 %r228, 0
  br label %bb_while_5_76_cond

bb_while_5_76_bre:
  call void @Dijkstra()
  %r293 = add i32 1, 0
  br label %bb_while_5_86_cond

bb_while_5_86_cond:
  %r294 = phi i32 [ %r293, %bb_while_5_76_bre ], [ %r295, %bb_while_5_86_whilestms ]
  %r230 = load i32, i32* @n
  %r231 = icmp sle i32 %r294, %r230
  br i1 %r231, label %bb_while_5_86_whilestms, label %bb_while_5_86_bre

bb_while_5_86_whilestms:
  %r233 = getelementptr [16 x i32 ], [16 x i32 ]* @dis, i32 0, i32 %r294
  %r234 = load i32, i32* %r233
  call void @putint(i32 %r234)
  call void @putch(i32 32)
  %r236 = add i32 %r294, 1
  %r295 = add i32 %r236, 0
  br label %bb_while_5_86_cond

bb_while_5_86_bre:
  call void @putch(i32 10)
  call void @_sysy_stoptime(i32 91)
  ret i32 0
}

