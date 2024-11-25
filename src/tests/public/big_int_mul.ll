declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@len = global i32 20
define i32 @main( ) {
bb1:
  %r298 = add i32 0, 0
  call void @_sysy_starttime(i32 97)
  %r299 = add i32 0, 0
  %r300 = add i32 0, 0
  %r301 = add i32 0, 0
  %r302 = add i32 0, 0
  %r303 = add i32 0, 0
  %r105 = alloca [ 20 x i32 ]
  %r106 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 0
  store i32 1, i32* %r106
  %r107 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 1
  store i32 2, i32* %r107
  %r108 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 2
  store i32 3, i32* %r108
  %r109 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 3
  store i32 4, i32* %r109
  %r110 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 4
  store i32 5, i32* %r110
  %r111 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 5
  store i32 6, i32* %r111
  %r112 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 6
  store i32 7, i32* %r112
  %r113 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 7
  store i32 8, i32* %r113
  %r114 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 8
  store i32 9, i32* %r114
  %r115 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 9
  store i32 0, i32* %r115
  %r116 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 10
  store i32 1, i32* %r116
  %r117 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 11
  store i32 2, i32* %r117
  %r118 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 12
  store i32 3, i32* %r118
  %r119 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 13
  store i32 4, i32* %r119
  %r120 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 14
  store i32 5, i32* %r120
  %r121 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 15
  store i32 6, i32* %r121
  %r122 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 16
  store i32 7, i32* %r122
  %r123 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 17
  store i32 8, i32* %r123
  %r124 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 18
  store i32 9, i32* %r124
  %r125 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 19
  store i32 0, i32* %r125
  %r126 = alloca [ 20 x i32 ]
  %r127 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 0
  store i32 2, i32* %r127
  %r128 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 1
  store i32 3, i32* %r128
  %r129 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 2
  store i32 4, i32* %r129
  %r130 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 3
  store i32 2, i32* %r130
  %r131 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 4
  store i32 5, i32* %r131
  %r132 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 5
  store i32 7, i32* %r132
  %r133 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 6
  store i32 9, i32* %r133
  %r134 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 7
  store i32 9, i32* %r134
  %r135 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 8
  store i32 0, i32* %r135
  %r136 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 9
  store i32 1, i32* %r136
  %r137 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 10
  store i32 9, i32* %r137
  %r138 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 11
  store i32 8, i32* %r138
  %r139 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 12
  store i32 7, i32* %r139
  %r140 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 13
  store i32 6, i32* %r140
  %r141 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 14
  store i32 4, i32* %r141
  %r142 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 15
  store i32 3, i32* %r142
  %r143 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 16
  store i32 2, i32* %r143
  %r144 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 17
  store i32 1, i32* %r144
  %r145 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 18
  store i32 2, i32* %r145
  %r146 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 19
  store i32 2, i32* %r146
  %r304 = add i32 0, 0
  %r148 = load i32, i32* @len
  %r305 = add i32 %r148, 0
  %r306 = add i32 0, 0
  %r150 = load i32, i32* @len
  %r307 = add i32 %r150, 0
  %r151 = alloca [ 25 x i32 ]
  %r152 = alloca [ 25 x i32 ]
  %r153 = alloca [ 40 x i32 ]
  %r154 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 0
  store i32 0, i32* %r154
  %r155 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 1
  store i32 0, i32* %r155
  %r156 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 2
  store i32 0, i32* %r156
  %r157 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 3
  store i32 0, i32* %r157
  %r158 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 4
  store i32 0, i32* %r158
  %r159 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 5
  store i32 0, i32* %r159
  %r160 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 6
  store i32 0, i32* %r160
  %r161 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 7
  store i32 0, i32* %r161
  %r162 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 8
  store i32 0, i32* %r162
  %r163 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 9
  store i32 0, i32* %r163
  %r164 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 10
  store i32 0, i32* %r164
  %r165 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 11
  store i32 0, i32* %r165
  %r166 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 12
  store i32 0, i32* %r166
  %r167 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 13
  store i32 0, i32* %r167
  %r168 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 14
  store i32 0, i32* %r168
  %r169 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 15
  store i32 0, i32* %r169
  %r170 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 16
  store i32 0, i32* %r170
  %r171 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 17
  store i32 0, i32* %r171
  %r172 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 18
  store i32 0, i32* %r172
  %r173 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 19
  store i32 0, i32* %r173
  %r174 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 20
  store i32 0, i32* %r174
  %r175 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 21
  store i32 0, i32* %r175
  %r176 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 22
  store i32 0, i32* %r176
  %r177 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 23
  store i32 0, i32* %r177
  %r178 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 24
  store i32 0, i32* %r178
  %r179 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 25
  store i32 0, i32* %r179
  %r180 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 26
  store i32 0, i32* %r180
  %r181 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 27
  store i32 0, i32* %r181
  %r182 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 28
  store i32 0, i32* %r182
  %r183 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 29
  store i32 0, i32* %r183
  %r184 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 30
  store i32 0, i32* %r184
  %r185 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 31
  store i32 0, i32* %r185
  %r186 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 32
  store i32 0, i32* %r186
  %r187 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 33
  store i32 0, i32* %r187
  %r188 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 34
  store i32 0, i32* %r188
  %r189 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 35
  store i32 0, i32* %r189
  %r190 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 36
  store i32 0, i32* %r190
  %r191 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 37
  store i32 0, i32* %r191
  %r192 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 38
  store i32 0, i32* %r192
  %r193 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 39
  store i32 0, i32* %r193
  %r308 = add i32 0, 0
  br label %bb_while_5_20_cond

bb_while_5_20_cond:
  %r309 = phi i32 [ %r308, %bb1 ], [ %r310, %bb_while_5_20_whilestms ]
  %r196 = icmp slt i32 %r309, %r305
  br i1 %r196, label %bb_while_5_20_whilestms, label %bb_while_5_20_bre

bb_while_5_20_whilestms:
  %r198 = getelementptr [25 x i32 ], [25 x i32 ]* %r151, i32 0, i32 %r309
  %r200 = getelementptr [20 x i32 ], [20 x i32 ]* %r105, i32 0, i32 %r309
  %r201 = load i32, i32* %r200
  store i32 %r201, i32* %r198
  %r203 = add i32 %r309, 1
  %r310 = add i32 %r203, 0
  br label %bb_while_5_20_cond

bb_while_5_20_bre:
  %r311 = add i32 0, 0
  br label %bb_while_5_26_cond

bb_while_5_26_cond:
  %r312 = phi i32 [ %r311, %bb_while_5_20_bre ], [ %r313, %bb_while_5_26_whilestms ]
  %r206 = icmp slt i32 %r312, %r307
  br i1 %r206, label %bb_while_5_26_whilestms, label %bb_while_5_26_bre

bb_while_5_26_whilestms:
  %r208 = getelementptr [25 x i32 ], [25 x i32 ]* %r152, i32 0, i32 %r312
  %r210 = getelementptr [20 x i32 ], [20 x i32 ]* %r126, i32 0, i32 %r312
  %r211 = load i32, i32* %r210
  store i32 %r211, i32* %r208
  %r213 = add i32 %r312, 1
  %r313 = add i32 %r213, 0
  br label %bb_while_5_26_cond

bb_while_5_26_bre:
  %r216 = add i32 %r305, %r307
  %r217 = sub i32 %r216, 1
  %r314 = add i32 %r217, 0
  %r315 = add i32 0, 0
  br label %bb_while_5_34_cond

bb_while_5_34_cond:
  %r316 = phi i32 [ %r315, %bb_while_5_26_bre ], [ %r317, %bb_while_5_34_whilestms ]
  %r220 = icmp sle i32 %r316, %r314
  br i1 %r220, label %bb_while_5_34_whilestms, label %bb_while_5_34_bre

bb_while_5_34_whilestms:
  %r222 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r316
  store i32 0, i32* %r222
  %r224 = add i32 %r316, 1
  %r317 = add i32 %r224, 0
  br label %bb_while_5_34_cond

bb_while_5_34_bre:
  %r318 = add i32 0, 0
  %r226 = sub i32 %r307, 1
  %r319 = add i32 %r226, 0
  br label %bb_while_5_42_cond

bb_while_5_42_cond:
  %r320 = phi i32 [ %r318, %bb_while_5_34_bre ], [ %r328, %bb_while_9_45_bre ]
  %r321 = phi i32 [ %r301, %bb_while_5_34_bre ], [ %r326, %bb_while_9_45_bre ]
  %r322 = phi i32 [ %r298, %bb_while_5_34_bre ], [ %r329, %bb_while_9_45_bre ]
  %r323 = phi i32 [ %r300, %bb_while_5_34_bre ], [ %r330, %bb_while_9_45_bre ]
  %r324 = phi i32 [ %r319, %bb_while_5_34_bre ], [ %r338, %bb_while_9_45_bre ]
  %r325 = phi i32 [ %r314, %bb_while_5_34_bre ], [ %r337, %bb_while_9_45_bre ]
  %r228 = icmp sgt i32 %r324, -1
  br i1 %r228, label %bb_while_5_42_whilestms, label %bb_while_5_42_bre

bb_while_5_42_whilestms:
  %r230 = getelementptr [25 x i32 ], [25 x i32 ]* %r152, i32 0, i32 %r324
  %r231 = load i32, i32* %r230
  %r326 = add i32 %r231, 0
  %r233 = sub i32 %r305, 1
  %r327 = add i32 %r233, 0
  br label %bb_while_9_45_cond

bb_while_9_45_cond:
  %r328 = phi i32 [ %r320, %bb_while_5_42_whilestms ], [ %r332, %bb_if_13_47_end ]
  %r329 = phi i32 [ %r322, %bb_while_5_42_whilestms ], [ %r334, %bb_if_13_47_end ]
  %r330 = phi i32 [ %r327, %bb_while_5_42_whilestms ], [ %r335, %bb_if_13_47_end ]
  %r331 = phi i32 [ %r325, %bb_while_5_42_whilestms ], [ %r336, %bb_if_13_47_end ]
  %r235 = icmp sgt i32 %r330, -1
  br i1 %r235, label %bb_while_9_45_whilestms, label %bb_while_9_45_bre

bb_while_9_45_whilestms:
  %r237 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r331
  %r238 = load i32, i32* %r237
  %r241 = getelementptr [25 x i32 ], [25 x i32 ]* %r151, i32 0, i32 %r330
  %r242 = load i32, i32* %r241
  %r243 = mul i32 %r326, %r242
  %r244 = add i32 %r238, %r243
  %r332 = add i32 %r244, 0
  %r246 = icmp sge i32 %r332, 10
  br i1 %r246, label %bb_if_13_47_true, label %bb_if_13_47_false

bb_if_13_47_true:
  %r248 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r331
  store i32 %r332, i32* %r248
  %r252 = sub i32 %r331, 1
  %r333 = add i32 %r252, 0
  %r254 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r333
  %r256 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r333
  %r257 = load i32, i32* %r256
  %r259 = sdiv i32 %r332, 10
  %r260 = add i32 %r257, %r259
  store i32 %r260, i32* %r254
  br label %bb_if_13_47_end

bb_if_13_47_false:
  %r262 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r331
  store i32 %r332, i32* %r262
  br label %bb_if_13_47_end

bb_if_13_47_end:
  %r334 = phi i32 [ %r333, %bb_if_13_47_true ], [ %r329, %bb_if_13_47_false ]
  %r265 = sub i32 %r330, 1
  %r335 = add i32 %r265, 0
  %r267 = sub i32 %r331, 1
  %r336 = add i32 %r267, 0
  br label %bb_while_9_45_cond

bb_while_9_45_bre:
  %r270 = add i32 %r331, %r305
  %r271 = sub i32 %r270, 1
  %r337 = add i32 %r271, 0
  %r273 = sub i32 %r324, 1
  %r338 = add i32 %r273, 0
  br label %bb_while_5_42_cond

bb_while_5_42_bre:
  %r274 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 0
  %r275 = load i32, i32* %r274
  %r276 = icmp ne i32 %r275, 0
  br i1 %r276, label %bb_if_5_62_true, label %bb_if_5_62_false

bb_if_5_62_true:
  %r277 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 0
  %r278 = load i32, i32* %r277
  call void @putint(i32 %r278)
  br label %bb_if_5_62_end

bb_if_5_62_false:
  br label %bb_if_5_62_end

bb_if_5_62_end:
  %r339 = add i32 1, 0
  br label %bb_while_5_67_cond

bb_while_5_67_cond:
  %r340 = phi i32 [ %r339, %bb_if_5_62_end ], [ %r341, %bb_while_5_67_whilestms ]
  %r282 = add i32 %r305, %r307
  %r283 = sub i32 %r282, 1
  %r284 = icmp sle i32 %r340, %r283
  br i1 %r284, label %bb_while_5_67_whilestms, label %bb_while_5_67_bre

bb_while_5_67_whilestms:
  %r286 = getelementptr [40 x i32 ], [40 x i32 ]* %r153, i32 0, i32 %r340
  %r287 = load i32, i32* %r286
  call void @putint(i32 %r287)
  %r289 = add i32 %r340, 1
  %r341 = add i32 %r289, 0
  br label %bb_while_5_67_cond

bb_while_5_67_bre:
  call void @_sysy_stoptime(i32 117)
  ret i32 0
}

