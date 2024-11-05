declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @Merge( i32* %r100, i32 %r101, i32 %r103, i32 %r105 ) {
bb1:
  %r260 = add i32 0, 0
  %r261 = add i32 0, 0
  %r262 = add i32 %r101, 0
  %r263 = add i32 0, 0
  %r264 = add i32 %r103, 0
  %r265 = add i32 0, 0
  %r266 = add i32 %r105, 0
  %r267 = add i32 0, 0
  %r268 = sub i32 %r264, %r262
  %r269 = add i32 %r268, 1
  %r270 = add i32 %r269, 0
  %r271 = add i32 0, 0
  %r272 = sub i32 %r266, %r264
  %r273 = add i32 %r272, 0
  %r116 = alloca [ 10 x i32 ]
  %r117 = alloca [ 10 x i32 ]
  %r274 = add i32 0, 0
  %r275 = add i32 0, 0
  %r276 = add i32 0, 0
  %r277 = add i32 0, 0
  %r278 = add i32 0, 0
  br label %bb2

bb2:
  %r279 = phi i32 [ %r275, %bb1 ], [ %r348, %bb3 ]
  %r280 = icmp slt i32 %r279, %r270
  br i1 %r280, label %bb3, label %bb4

bb3:
  %r342 = add i32 %r279, %r262
  %r343 = add i32 %r342, 0
  %r344 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r279
  %r345 = getelementptr i32, i32* %r100, i32 %r343
  %r346 = load i32, i32* %r345
  store i32 %r346, i32* %r344
  %r347 = add i32 %r279, 1
  %r348 = add i32 %r347, 0
  br label %bb2

bb4:
  br label %bb5

bb5:
  %r281 = phi i32 [ %r277, %bb4 ], [ %r341, %bb6 ]
  %r282 = icmp slt i32 %r281, %r273
  br i1 %r282, label %bb6, label %bb7

bb6:
  %r334 = add i32 %r281, %r264
  %r335 = add i32 %r334, 1
  %r336 = add i32 %r335, 0
  %r337 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r281
  %r338 = getelementptr i32, i32* %r100, i32 %r336
  %r339 = load i32, i32* %r338
  store i32 %r339, i32* %r337
  %r340 = add i32 %r281, 1
  %r341 = add i32 %r340, 0
  br label %bb5

bb7:
  %r283 = add i32 0, 0
  %r284 = add i32 0, 0
  %r285 = add i32 %r262, 0
  br label %bb8

bb8:
  %r286 = phi i32 [ %r285, %bb7 ], [ %r317, %bb14 ]
  %r287 = phi i32 [ %r283, %bb7 ], [ %r318, %bb14 ]
  %r288 = phi i32 [ %r284, %bb7 ], [ %r319, %bb14 ]
  %r289 = icmp ne i32 %r287, %r270
  br i1 %r289, label %bb11, label %bb10

bb11:
  %r310 = icmp ne i32 %r288, %r273
  br i1 %r310, label %bb9, label %bb10

bb9:
  %r311 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r287
  %r312 = load i32, i32* %r311
  %r313 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r288
  %r314 = load i32, i32* %r313
  %r315 = add i32 %r314, 1
  %r316 = icmp slt i32 %r312, %r315
  br i1 %r316, label %bb12, label %bb13

bb12:
  %r327 = getelementptr i32, i32* %r100, i32 %r286
  %r328 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r287
  %r329 = load i32, i32* %r328
  store i32 %r329, i32* %r327
  %r330 = add i32 %r286, 1
  %r331 = add i32 %r330, 0
  %r332 = add i32 %r287, 1
  %r333 = add i32 %r332, 0
  br label %bb14

bb13:
  %r320 = getelementptr i32, i32* %r100, i32 %r286
  %r321 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r288
  %r322 = load i32, i32* %r321
  store i32 %r322, i32* %r320
  %r323 = add i32 %r286, 1
  %r324 = add i32 %r323, 0
  %r325 = add i32 %r288, 1
  %r326 = add i32 %r325, 0
  br label %bb14

bb14:
  %r317 = phi i32 [ %r331, %bb12 ], [ %r324, %bb13 ]
  %r318 = phi i32 [ %r333, %bb12 ], [ %r287, %bb13 ]
  %r319 = phi i32 [ %r288, %bb12 ], [ %r326, %bb13 ]
  br label %bb8

bb10:
  br label %bb15

bb15:
  %r290 = phi i32 [ %r286, %bb10 ], [ %r307, %bb16 ]
  %r291 = phi i32 [ %r287, %bb10 ], [ %r309, %bb16 ]
  %r292 = icmp slt i32 %r291, %r270
  br i1 %r292, label %bb16, label %bb17

bb16:
  %r303 = getelementptr i32, i32* %r100, i32 %r290
  %r304 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r291
  %r305 = load i32, i32* %r304
  store i32 %r305, i32* %r303
  %r306 = add i32 %r290, 1
  %r307 = add i32 %r306, 0
  %r308 = add i32 %r291, 1
  %r309 = add i32 %r308, 0
  br label %bb15

bb17:
  br label %bb18

bb18:
  %r293 = phi i32 [ %r290, %bb17 ], [ %r300, %bb19 ]
  %r294 = phi i32 [ %r288, %bb17 ], [ %r302, %bb19 ]
  %r295 = icmp slt i32 %r294, %r273
  br i1 %r295, label %bb19, label %bb20

bb19:
  %r296 = getelementptr i32, i32* %r100, i32 %r293
  %r297 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r294
  %r298 = load i32, i32* %r297
  store i32 %r298, i32* %r296
  %r299 = add i32 %r293, 1
  %r300 = add i32 %r299, 0
  %r301 = add i32 %r294, 1
  %r302 = add i32 %r301, 0
  br label %bb18

bb20:
  ret i32 0
}

define i32 @MergeSort( i32* %r206, i32 %r207, i32 %r209 ) {
bb21:
  %r349 = add i32 0, 0
  %r350 = add i32 0, 0
  %r351 = add i32 0, 0
  %r352 = add i32 %r207, 0
  %r353 = add i32 0, 0
  %r354 = add i32 %r209, 0
  %r355 = icmp slt i32 %r352, %r354
  br i1 %r355, label %bb22, label %bb23

bb22:
  %r356 = add i32 %r352, %r354
  %r357 = sdiv i32 %r356, 2
  %r358 = add i32 %r357, 0
  %r359 = call i32 @MergeSort(i32* %r206, i32* %r352, i32* %r358)
  %r360 = add i32 %r359, 0
  %r361 = add i32 %r358, 1
  %r362 = add i32 %r361, 0
  %r363 = call i32 @MergeSort(i32* %r206, i32* %r362, i32* %r354)
  %r364 = add i32 %r363, 0
  %r365 = call i32 @Merge(i32* %r206, i32* %r352, i32* %r358, i32* %r354)
  %r366 = add i32 %r365, 0
  br label %bb23

bb23:
  ret i32 0
}

define i32 @main( ) {
bb24:
  call void @_sysy_starttime(i32 71)
  store i32 10, i32* @n
  %r232 = alloca [ 10 x i32 ]
  %r367 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 0
  store i32 4, i32* %r367
  %r368 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 1
  store i32 3, i32* %r368
  %r369 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 2
  store i32 9, i32* %r369
  %r370 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 3
  store i32 2, i32* %r370
  %r371 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 4
  store i32 0, i32* %r371
  %r372 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 5
  store i32 1, i32* %r372
  %r373 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 6
  store i32 6, i32* %r373
  %r374 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 7
  store i32 5, i32* %r374
  %r375 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 8
  store i32 7, i32* %r375
  %r376 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 9
  store i32 8, i32* %r376
  %r377 = add i32 0, 0
  %r378 = add i32 0, 0
  %r379 = add i32 0, 0
  %r380 = load i32, i32* @n
  %r381 = sub i32 %r380, 1
  %r382 = add i32 %r381, 0
  %r383 = call i32 @MergeSort(i32* %r232, i32* %r378, i32* %r382)
  %r384 = add i32 %r383, 0
  br label %bb25

bb25:
  %r385 = phi i32 [ %r384, %bb24 ], [ %r393, %bb26 ]
  %r386 = load i32, i32* @n
  %r387 = icmp slt i32 %r385, %r386
  br i1 %r387, label %bb26, label %bb27

bb26:
  %r388 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 %r385
  %r389 = load i32, i32* %r388
  %r390 = add i32 %r389, 0
  call void @putint(i32* %r390)
  %r391 = add i32 10, 0
  call void @putch(i32* %r391)
  %r392 = add i32 %r385, 1
  %r393 = add i32 %r392, 0
  br label %bb25

bb27:
  call void @_sysy_stoptime(i32 97)
  ret i32 0
}

